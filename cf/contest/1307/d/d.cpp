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

vi bfs(graph& g, int u) {
	vi dist(g.size, INF);
	vb visit(g.size, false);
	queue<int> q;
	dist[u] = 0;
	visit[u] = true;
	q.push(u);
	while (!q.empty()) {
		u = q.front();
		q.pop();
		for (int v : g.adj[u]) {
			if (visit[v]) continue;
			visit[v] = true;
			dist[v] = dist[u] + 1;
			q.push(v);
		}
	}
	return dist;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;
	vi sp(k);
	loop(k) cin >> sp[i], sp[i]--;
	int a, b;
	graph g(n);
	loop(m) {
		cin >> a >> b;
		g.addEdge(a - 1, b - 1);
	}
	vi d1 = bfs(g, 0), dn = bfs(g, n - 1);
	vector<ii> p1, p2;
	each(x, sp) p1.emplace_back(d1[x], x), p2.emplace_back(dn[x], x);
	sort(iter(p1)), sort(iter(p2));
	int ans = 0;
	loop(k) {
		vloop(j, k) {
			if (i == j) continue;
			int f = min(d1[sp[i]] + dn[sp[j]] + 1, d1[sp[j]] + dn[sp[i]] + 1);/*@*/
			ans = max(ans, f);
			if (ans > d1[n - 1]) {
				ans = d1[n - 1];
				break;
			}
		}
		if (ans > d1[n - 1]) {
			ans = d1[n - 1];
			break;
		}
	}
	cout << ans << endl;
	return 0;
}

