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
	vector<list<ii>> adj;
	graph(int n) : size(n), adj(n) {}
	void addEdge(int a, int b, int w) {
		adj[a].emplace_back(b, w);
		adj[b].emplace_back(a, w);
	}
};

vi par, dist;
typedef tuple<int, int, int> iii;

void dijkstra(graph& g) {
	dist.resize(g.size, INF);
	vb visit(g.size, false);
	par.resize(g.size, -1);
	priority_queue<iii, vector<iii>, greater<iii>> q;
	dist[0] = 0;
	q.emplace(0, 0, -1);
	while (!q.empty()) {
		int d, u, p;
		tie(d, u, p) = q.top();
		q.pop();
		if (visit[u]) continue;
		visit[u] = true;
		dist[u] = d;
		par[u] = p;
		for (auto& [v, w] : g.adj[u]) {
			q.emplace(d + w, v, u);
		}
	}
}

list<int> path(int x) {
	if (par[x] == -1) return {x};
	list<int> p = path(par[x]);
	p.push_back(x);
	return p;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	int a, b, w;
	graph g(n);
	loop(m) {
		cin >> a >> b >> w;
		g.addEdge(a - 1, b - 1, w);
	}
	dijkstra(g);
	auto p = path(n - 1);
	if (*p.begin() == n - 1) cout << -1 << endl;
	else {
		each(x, p) cout << x + 1 << " ";
		cout << endl;
	}
	return 0;
}

