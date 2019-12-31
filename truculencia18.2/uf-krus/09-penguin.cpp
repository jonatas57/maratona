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
	vector<vector<ll>> adj;

	graph(int n) : size(n) {
		adj.resize(n, vector<ll>(n, 0));
	}

	void addEdge(int i, int j, ll w) {
		adj[i][j] = adj[j][i] = w;
	}

	auto getEdges() {
		vector<tuple<int, int, ll>> edges;
		loop(size) vloop(j, i) {
			edges.emplace_back(i, j, adj[i][j]);
		}
		return edges;
	}
};

vi id, sz;

void init(int n) {
	id.resize(n);
	sz.resize(n, 1);
	loop(n) id[i] = i;
}

int find(int p) { return p == id[p] ? p : id[p] = find(id[p]); }

void join(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (sz[a] > sz[b]) swap(a, b);
	id[a] = id[b];
	sz[b] += sz[a];
}

auto kruskal(graph& g) {
	ll cost = 0;
	vector<tuple<int, int, ll>> mst;
	auto es = g.getEdges();
	sort(iter(es), [](tuple<int, int, ll>& a, tuple<int, int, ll>& b) {
		return get<2>(a) < get<2>(b);
	});
	init(g.size);
	int u,v;
	ll w;
	each(e, es) {
		tie(u, v, w) = e;
		if (find(u) == find(v)) continue;
		join(u, v);
		cost += w;
		mst.push_back(e);
	}
	return make_pair(cost, mst);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, d, a;
	cin >> n >> d >> a;
	ll cost = 0;
	vector<string> ans(n, string(n, '0'));
	graph g(n);
	loop(n) {
		string s;
		cin >> s;
		vloop(j, i) {
			if (s[j] == '1') {
				g.addEdge(i, j, -d);
				cost += d;
				ans[i][j] = ans[j][i] = 'd';
			}
			else {
				g.addEdge(i, j, a);
			}
		}
	}
	ll del;
	vector<tuple<int, int, ll>> mst;
	tie(del, mst) = kruskal(g);
	for (auto& [u, v, w] : mst) {
		ans[u][v] = ans[v][u] = (w == a ? 'a' : '0');
	}
	cout << cost + del << endl;
	each(s, ans) cout << s << endl;
	return 0;
}

