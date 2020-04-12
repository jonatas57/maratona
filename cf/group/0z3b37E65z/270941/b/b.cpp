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
	void addEdge(int a, int b, int w) {
		adj[a].push_back(w);
	}
};

typedef tuple<int, int, int> iii;

vi par;
void dijkstra(graph& g, int maxd) {
	vi dist(g.size, INF);
	vb visit(g.size, false);
	priority_queue<iii, vector<iii>, greater<iii>> q;
	par.resize(g.size, -1);
	dist[0] = 0;
	visit[0] = true;
	q.emplace(0, -1, 0);
	int u, d, p;
	while (!q.empty()) {
		tie(d, p, u) = q.front();
		q.pop();
		if (visit[u]) continue;
		visit[u] = true;
		par[u] = p;
		for (auto& [v, w] : g.adj[u]) {
			if (visit[v] or d + w > maxd) continue;
			dist[v] = min(dist[v], dist[u] + w);
			q.emplace(dist[v], u, v);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, m, t;
	cin >> n >> m >> t;
	graph g(n);
	int a, b, w;
	loop(m) {
		cin >> a >> b >> w;
		g.addEdge(a - 1, b - 1, w);
	}
	return 0;
}

