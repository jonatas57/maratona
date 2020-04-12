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

vb prime(32, true), used(17, false);
vi path;

void dfs(graph& g, int u, int n, int d = 1) {
	used[u] = true;
	path.push_back(u);
	if (d == n) {
		bool p = false;
		each(x, g.adj[u]) if (x == 1) p = true;
		if (p) {
			loop(n) {
				if (i) cout << " ";
				cout << path[i];
			}
			cout << endl;
		}
	}
	else {
		each(v, g.adj[u]) {
			if (used[v] or v > n) continue;
			dfs(g, v, n, d + 1);
		}
	}
	used[u] = false;
	path.pop_back();
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	prime[0] = prime[1] = false;
	for (int i = 2;i < 32;i++) {
		if (!prime[i]) continue;
		for (int j = i << 1;j < 32;j += i) prime[j] = false;
	}
	int n;
	for (int t = 1;cin >> n;t++) {
		graph g(n + 1);
		for (int i = 1;i <= n;i++) {
			for (int j = 1;j < i;j++) {
				if (prime[j + i]) g.addEdge(j, i);
			}
		}
		if (t > 1) cout << endl;
		cout << "Case " << t << ":" << endl;
		dfs(g, 1, n);
	}
	return 0;
}

