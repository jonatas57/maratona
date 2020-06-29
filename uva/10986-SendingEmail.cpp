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

struct graph {
	int size;
	vector<list<ii>> adj;
	graph(int n) : size(n), adj(n) {}
	void addEdge(int a, int b, int c) {
		adj[a].emplace_back(b, c);
		adj[b].emplace_back(a, c);
	}
};

int dijkstra(graph& g, int s, int t) {
	vi dist(g.size, INF);
	vb visit(g.size, false);
	priority_queue<ii, vector<ii>, greater<ii>> pq;
	dist[s] = 0;
	pq.emplace(0, s);
	int u, d;
	while (!pq.empty()) {
		tie(d, u) = pq.top();
		pq.pop();
		if (visit[u]) continue;
		visit[u] = true;
		each(p, g.adj[u]) {
			int v, w;
			tie(v, w) = p;
			if (visit[v]) continue;
			dist[v] = min(d + w, dist[v]);
			pq.emplace(dist[v], v);
		}
	}
	return dist[t];
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		int n, m, s, t;
		cin >> n >> m >> s >> t;
		int a, b, c;
		graph g(n);
		loop(m) {
			cin >> a >> b >> c;
			g.addEdge(a, b, c);
		}
		cout << "Case #" << i + 1 << ": ";
		int ans = dijkstra(g, s, t);
		if (ans == INF) cout << "unreachable" << endl;
		else cout << ans << endl;
	}
	return 0;
}

