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

vi c;
int countColors(graph& g, int u = 0, int p = -1, int pc = -1) {
	int ans = 0;
	if (c[u] != pc) ans++;
	each(v, g.adj[u]) {
		if (v == p) continue;
		ans += countColors(g, v, u, c[u]);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	graph g(n);
	int p;
	loop(n - 1) {
		cin >> p;
		g.addEdge(p - 1, i + 1);
	}
	c.resize(n);
	loop(n) cin >> c[i];
	cout << countColors(g) << endl;
	return 0;
}

