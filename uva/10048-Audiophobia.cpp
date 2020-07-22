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

int dijkstra(graph& g, int x, int y) {
	vi dist(g.size, INF);
	vb visit(g.size, false);
	priority_queue<ii> q;
	dist[x] = 0;
	q.emplace(0, x);
	int d, u;
	while (!q.empty()) {
		tie(d, u) = q.top();
		q.pop();
		if (visit[u]) continue;
		visit[u] = true;
		int v, w;
		each(p, g.adj[u]) {
			tie(v, w) = p;
			if (visit[v]) continue;
			dist[v] = min(dist[v], max(-d, w));
			q.emplace(-dist[v], v);
		}
	}
	return dist[y];
};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int c, s, q;
	for (int i = 1;cin >> c >> s >> q and c | s | q;i++) {
		if (i > 1) cout << endl;
		graph g(c);
		int x, y, z;
		loop(s) {
			cin >> x >> y >> z;
			g.addEdge(x - 1, y - 1, z);
		}
		cout << "Case #" << i << endl;
		loop(q) {
			cin >> x >> y;
			int ans = dijkstra(g, x - 1, y - 1);
			if (ans == INF) cout << "no path" << endl;
			else cout << ans << endl;
		}
	}
	return 0;
}

