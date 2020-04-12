#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define MAX                100000
#define N                  4 * MAX + 10
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define ceach(x, s)        for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2

struct graph {
	int size;
	vector<list<int>> adj;
	vi par;
	graph(int n) : size(n) {
		adj.resize(n);
		par.resize(n, -1);
	}
	void addEdge(int a, int b) {
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
};

vi dist, md;
vb visit;
int bfs(graph& g, int x, int d) {
	if (!x) dist.resize(g.size), md.resize(g.size, 0), visit.resize(g.size, false);
	visit[x] = true;
	dist[x] = md[x] = d;
	each(v, g.adj[x]) {
		if (!visit[v]) {
			visit[v] = true;
			g.par[v] = x;
			md[x] = max(md[x], bfs(g, v, d + 1));
		}
	}
	return md[x];
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	
	int n, x;
	cin >> n >> x;
	graph g(n);
	x--;
	int a, b;
	loop(n - 1) {
		cin >> a >> b;
		g.addEdge(a - 1, b - 1);
	}
	bfs(g, 0, 0);
	int l = (dist[x] - 1) / 2;
	int m = md[x];
	loop(l) {
		x = g.par[x];
		m = max(m, md[x]);
	}
	cout << 2 * m << endl;
	return 0;
}

