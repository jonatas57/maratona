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
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

struct graph {
	int size;
	vector<list<int>> adj;
	vb val;
	graph(int n) : size(n) {
		adj.resize(n);
		val.resize(n);
	}
	void addEdge(int a, int b) {
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
};

vi ans;
vb goal;

void dfs(graph& g, int u, int p, bool fnow, bool fch) {
	if (fnow) g.val[u].flip();
	if (g.val[u] != goal[u]) {
		ans.push_back(u + 1);
		fnow ^= 1;
	}
	each(x, g.adj[u]) {
		if (x != p) {
			dfs(g, x, u, fch, fnow);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	int u, v;
	graph g(n);
	loop(n - 1) {
		cin >> u >> v;
		g.addEdge(u - 1, v - 1);
	}
	int b;
	loop(n) cin >> b, g.val[i] = b;
	goal.resize(n);
	loop(n) cin >> b, goal[i] = b;
	dfs(g, 0, -1, false, false);
	cout << ans.size() << endl;
	each(x, ans) cout << x << endl;
	return 0;
}
