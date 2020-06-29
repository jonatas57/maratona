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

typedef tuple<int, int, int> tup;

struct graph {
	int size;
	vector<list<tup>> adj;
	graph(int n) : size(n), adj(n) {}
	void addEdge(int a, int b, int t, int s) {
		adj[a].emplace_back(b, t, s);
		adj[b].emplace_back(a, t, s);
	}
};

int dijkstra(graph& g, int maxs, int maxt) {
	int n = g.size;
	vb visit(n, false);
	priority_queue<tup, vector<tup>, greater<tup>> q;
	q.emplace(0, 0, 0);
	int u, d, s;
	while (!q.empty()) {
		tie(d, u, s) = q.top();
		q.pop();
		if (visit[u]) continue;
		if (u == n - 1) return d;
		visit[u] = true;
		for (auto& [v, w, ns] : g.adj[u]) {
			if (visit[v] or d + w > maxt or ns > maxs) continue;
			q.emplace(d + w, v, max(ns, s));
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	graph g(n);
	int a, b, d, s;
	loop(m) {
		cin >> a >> b >> d >> s;
		g.addEdge(a - 1, b - 1, d, s);
	}
	int t;
	cin >> t;
	int l = 0, r = 1000001, ans = -1;
	while (l < r) {
		int mid = avg(l, r), aux;
		if ((aux = dijkstra(g, mid, t)) == -1) l = mid + 1;
		else ans = aux, r = mid;
	}
	if (ans == -1) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
		cout << r << " " << ans << endl;
	}
	return 0;
}

