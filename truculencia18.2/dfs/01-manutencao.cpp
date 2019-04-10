#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define each(x, s)         for(auto& x : s)
#define ceach(x, s)        for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define pb                 push_back

struct graph {
	int size, root;
	map<int, map<int, bool>> adj;
	vi num, low, par;
	vb visit;
	int counter, ch;

	graph(int n) : size(n), root(1), counter(0), ch(0) {
		visit.resize(size + 1, false);
		num.resize(n + 1, INF);
		low.resize(n + 1, INF);
		par.resize(n + 1, INF);
	}
	void addEdge(int a, int b) {
		adj[a][b] = adj[b][a] = true;
	}
	set<int> findArt(int v) {
		visit[v] = true;
		low[v] = num[v] = counter++;
		set<int> art;
		each(p, adj[v]) {
			int w = p.first;
			if (!p.second) continue;
			if (!visit[w]) {
				if (v == root) ch++;
				par[w] = v;
				auto aux = findArt(w);
				art.insert(aux.begin(), aux.end());
				if (low[w] >= num[v]) {
					art.insert(v);
				}
				low[v] = min(low[v], low[w]);
			}
			else {
				if (par[v] != w) {
					low[v] = min(low[v], num[w]);
				}
			}
		}
		return art;
	}
};


int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	int n, m, t = 1;
	while (cin >> n >> m && (n | m)) {
		int x, y;
		graph g(n);
		loop(m) cin >> x >> y, g.addEdge(x, y);
		auto ans = g.findArt(1);
		cout << "Teste " << t++ << endl;
		if (g.ch <= 1) ans.erase(1);
		if (ans.size()) each(v, ans) cout << v << " ";
		else cout << "nenhum";
		cout << endl << endl;
	}
	return 0;
}
