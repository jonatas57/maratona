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
	vector<mii> adj;
	vi deg;
	graph(int n) : size(n) {
		adj.resize(n);
		deg.resize(n, 0);
	}
	void addEdge(int a, int b) {
		adj[a][b] = adj[b][a] = 1;
		deg[a]++, deg[b]++;
	}
};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	int x, y;
	graph g(n);
	loop(m){
		cin >> x >> y;
		g.addEdge(x - 1, y - 1);
	}
	int mind = INF, id;
	loop(n) {
		if (g.deg[i] < mind) mind = g.deg[i], id = i;
	}
	vb p(n, true);
	p[id] = false;
	each(q, g.adj[id]) p[q.first] = false;
	loop(n) cout << p[i] << " ";
	cout << endl;
	return 0;
}

