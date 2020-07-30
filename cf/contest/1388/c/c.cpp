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
	vector<list<int>> adj;
	vi deg;
	graph(int n) : size(n), adj(n), deg(n, 0) {}
	void addEdge(int a, int b) {
		adj[a].push_back(b);
		adj[b].push_back(a);
		deg[a]++;
		deg[b]++;
	}
};

const int N = 100000;
vector<ll> p(N), h(N), maxy(N);
bool dfs(graph& g, int u, int par = -1) {
	bool ok = true;
	maxy[u] = p[u];
	each(v, g.adj[u]) {
		if (v == par) continue;
		ok &= dfs(g, v, u);
	}
	int dx = abs(p[u] + h[u]);
	int y = p[u] - dx / 2;
	if (par != -1) {
		p[par] += p[u];
		maxy[par] += y;
	}
	if (dx & 1 or abs(h[u]) > p[u] or maxy[u] < y) return false;
	return ok;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		int n, m;
		cin >> n >> m;
		loop(n) cin >> p[i];
		loop(n) cin >> h[i];
		graph g(n);
		int u, v;
		loop(n - 1) {
			cin >> u >> v;
			g.addEdge(u - 1, v - 1);
		}
		cout << (dfs(g, 0) ? "YES" : "NO") << endl;
	}
	return 0;
}

