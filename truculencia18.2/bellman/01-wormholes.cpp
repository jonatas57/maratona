#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define each(x, s)         for(auto& x : s)
#define ceach(x, s)        for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define pb                 push_back

struct graph {
	int size;
	map<int, mii> adj;

	graph(int n) : size(n) {}
	void addEdge(int a, int b, int w) {
		adj[a][b] = w;
	}
	mii& operator[](int i) {
		return adj[i];
	}
};

bool negativeCycle(graph& g) {
	vi dist(g.size + 1, INF);
	vb visit(g.size + 1, false);
	dist[1] = 0;

	loop(g.size - 1) {
		each(p, g.adj) {
			int u = p.first;
			each(q, p.second) {
				int v = q.first, w = q.second;
				dist[v] = min(dist[v], dist[u] + w);
			}
		}
	}
	each(p, g.adj) {
		int u = p.first;
		each(q, p.second) {
			int v = q.first, w = q.second;
			if (dist[u] + w < dist[v]) return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	int c, n, m, a, b, w;
	cin >> c;
	loop(c) {
		cin >> n >> m;
		graph g(n);
		loop(m) {
			cin >> a >> b >> w;
			g.addEdge(a, b, w);
		}
		bool p = negativeCycle(g);
		cout << (p ? "possible\n" : "not possible\n");
	}
	return 0;
}
