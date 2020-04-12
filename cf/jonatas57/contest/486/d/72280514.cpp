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
	vi val;
	graph(int n) : size(n), adj(n), val(n) {}
	void addEdge(int a, int b) {
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
};

vb visit;
int root;
ll dfs(graph& g, int l, int r, int u, int p = -1) {
	ll ans = 1;
	if (g.val[u] == l) visit[u] = true;
	for (int v : g.adj[u]) {
		if (v == p or g.val[v] < l or g.val[v] > r) continue;
		if (g.val[v] == l and v < root) continue;
		ans *= dfs(g, l, r, v, u) + 1;
		ans %= mod;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int d, n;
	cin >> d >> n;
	int a, b;
	graph g(n);
	loop(n) cin >> g.val[i];
	loop(n - 1) {
		cin >> a >> b;
		g.addEdge(a - 1, b - 1);
	}
	ll ans = 0;
	visit.assign(n, false);
	loop(n) {
		root = i;
		ans += dfs(g, g.val[i], g.val[i] + d, i);
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}

