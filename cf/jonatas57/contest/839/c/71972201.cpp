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

vb visit;
double dfs(graph& g, int u) {
	visit[u] = true;
	int x = 0;
	each(v, g.adj[u]) {
		if (!visit[v]) x++;
	}
	double sum = 0;
	each(v, g.adj[u]) {
		if (visit[v]) continue;
		sum += dfs(g, v);
	}
	return x ? sum / x + 1 : 0;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	graph g(n);
	loop(n - 1) {
		int a, b;
		cin >> a >> b;
		g.addEdge(a - 1, b - 1);
	}
	visit.assign(n, false);
	cout << fixed << setprecision(15) << dfs(g, 0) << endl;
	return 0;
}
