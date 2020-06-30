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
	graph(int n) : size(n), adj(n) {}
	void addEdge(int a, int b) {
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
};

vector<ll> vs;
int dfs(graph& g, int u, int p = -1, int dep = 0) {
	int ch = 0;
	each(v, g.adj[u]) {
		if (v != p) {
			ch += dfs(g, v, u, dep + 1);
		}
	}
	vs.push_back(dep - ch);
	return ch + 1;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	graph g(n);
	int a, b;
	loop(n - 1) {
		cin >> a >> b;
		g.addEdge(a - 1, b - 1);
	}
	vs.clear();
	dfs(g, 0);
	sort(riter(vs));
	ll ans = 0;
	loop(k) {
		ans += vs[i];
	}
	cout << ans << endl;
	return 0;
}

