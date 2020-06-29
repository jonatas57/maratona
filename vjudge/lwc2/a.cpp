#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define INFLL              0x3f3f3f3f3f3f3f3f
#define each(x, s)         for(auto& x : s)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

const ll mod = 1000000007;

typedef tuple<int, int, int> tup;

struct graph {
	int size;
	vector<list<tup>> adj;
	map<string, int> ns;
	graph(int n) : size(0) {}
	void addEdge(string a, string b, string w) {
		int x = addNode(a);
		int y = addNode(b);
		adj[x].emplace_back(y, w.length(), w[0] - 'a');
		adj[y].emplace_back(x, w.length(), w[0] - 'a');
	}
	int addNode(string s) {
		if (!ns[s]) {
			ns[s] = ++size;
			adj.emplace_back();
		}
		return ns[s] - 1;
	}
};

int dijkstra(graph& g, int s, int t) {
	vector<vi> dist(g.size, vi(26, INF));
	vector<vb> visit(g.size, vb(26, false));
	priority_queue<tup, vector<tup>, greater<tup>> q;
	loop(26) {
		dist[s][i] = 0;
		q.emplace(0, s, i);
	}
	int d, u, lc, v, w, nc;
	while (!q.empty()) {
		tie(d, u, lc) = q.top();
		q.pop();
		if (visit[u][lc]) continue;
		visit[u][lc] = true;
		if (u == t) return d;
		each(p, g.adj[u]) {
			tie(v, w, nc) = p;
			if (lc == nc or visit[v][nc]) continue;
			dist[v][nc] = min(dist[v][nc], dist[u][lc] + w);
			q.emplace(dist[v][nc], v, nc);
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	while (cin >> n and n) {
		graph g(n);
		string s, t, a, b, w;
		cin >> s >> t;
		g.addNode(s);
		g.addNode(t);
		loop(n) {
			cin >> a >> b >> w;
			g.addEdge(a, b, w);
		}
		int ans = dijkstra(g, g.ns[s] - 1, g.ns[t] - 1);
		if (ans < 0) cout << "impossivel" << endl;
		else cout << ans << endl;
	}
	return 0;
}

