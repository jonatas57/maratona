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
	vi h;
	graph(int n) : size(n), adj(n), h(n) {}
	void addEdge(int a, int b) {
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
};

vb vis(1e5, false);
int dfs(graph& g, int u) {
	vis[u] = true;
	int ans = 0;
	bool good = true;
	each(v, g.adj[u]) {
		if (g.h[u] <= g.h[v]) good = false;
		if (vis[v]) continue;
		ans += dfs(g, v);
	}
	if (good) ans++;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	graph g(n);
	loop(n) cin >> g.h[i];
	int a, b;
	loop(m) {
		cin >> a >> b;
		g.addEdge(a - 1, b - 1);
	}
	int ans = 0;
	loop(n) {
		if (!vis[i]) ans += dfs(g, i);
	}
	cout << ans << endl;
	return 0;
}

