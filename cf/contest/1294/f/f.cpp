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

typedef tuple<int, int, int> leaf;     // dist, v, b
typedef tuple<int, int, int, int> tup; // dist, a, lca, b

vb visit;
vi par;
pair<vector<leaf>, tup> dfs(graph& g, int u) {
	visit[u] = true;
	vector<leaf> ls;
	tup ans(-1, 0, 0, 0);
	bool l = true;
	each(v, g.adj[u]) {
		if (!visit[v]) {
			l = false;
			vector<leaf> x;
			tup y;
			par[v] = u;
			tie(x, y) = dfs(g, v);
			if (get<0>(y) > get<0>(ans)) ans = y;
			ls.insert(ls.end(), iter(x));
		}
	}
	if (l) {
		ans = {0, u, u, u};
		ls.emplace_back(0, u, u);
	}
	else {
		sort(riter(ls));
		vector<leaf> aux;
		int last = -1;
		for (auto& [d, a, b] : ls) {
			d++;
			if (last != a) {
				last = a;
				aux.emplace_back(d, a, b);
			}
			a = u;
		}
		if (aux.size() >= 2) {
			int y = get<0>(aux[0]) + get<0>(aux[1]);
			if (y > get<0>(ans)) {
				ans = make_tuple(y, get<2>(aux[0]), u, get<2>(aux[1]));
			}
		}
	}
	return {ls, ans};
}

ii dfs2(graph& g, int u) {
	visit[u] = true;
	int x = u, dist = 0;
	each(v, g.adj[u]) {
		if (!visit[v]) {
			int a, b;
			tie(a, b) = dfs2(g, v);
			if (dist <= b) {
				x = a;
				dist = b + 1;
			}
		}
	}
	return {x, dist};
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	graph g(n);
	int a, b;
	loop(n - 1) {
		cin >> a >> b;
		g.addEdge(a - 1, b - 1);
	}
	tup ans;
	visit.resize(n, false);
	par.resize(n, -1);
	loop(n) {
		if (g.deg[i] > 1) {
			tie(ignore, ans) = dfs(g, i);
			break;
		}
	}
	visit.assign(n, false);
	vi path;
	int d;
	tie(d, a, ignore, b) = ans;
	for (int i = a;i != -1;i = par[i]) {
		path.push_back(i);
		visit[i] = true;
	}
	for (int i = b;i != -1;i = par[i]) {
		path.push_back(i);
		visit[i] = true;
	}
	int c = -1, m = 0;
	each(u, path) {
		int x, y;
		tie(x, y) = dfs2(g, u);
		if (y > m) {
			m = y;
			c = x;
		}
	}
	if (c == -1) c = par[a];
	cout << d + m << endl;
	cout << a + 1 << " " << b + 1 << " " << c + 1 << endl;
	return 0;
}

