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
	vector<list<tuple<int, ll, int>>> adj;
	graph(int n) : size(n), adj(n) {}
	void addEdge(int u, int v, ll w) {
		adj[u].emplace_back(v, w, 0);
		adj[v].emplace_back(u, w, 0);
	}
};

int dfs(graph& g, int u = 0, int par = -1) {
	int ch = 0;
	bool leaf = true;
	for (auto& [v, w, t] : g.adj[u]) {
		if (v == par) {
			t = -1;
			continue;
		}
		leaf = false;
		t = dfs(g, v, u);
		ch += t;
	}
	return leaf ? 1 : ch;
} 

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		int n;
		ll s;
		cin >> n >> s;
		graph g(n);
		int u, v;
		ll w;
		loop(n - 1) {
			cin >> u >> v >> w;
			g.addEdge(u - 1, v - 1, w);
		}
		dfs(g);
		priority_queue<tuple<ll, ll, int>> q;
		ll sum = 0;
		loop(n)	for (auto& [v, w, times] : g.adj[i]) {
			if (times == -1) continue;
			sum += times * w;
			q.emplace(((w + 1) / 2) * times, w, times);
		}
		int ans = 0;
		while (sum > s) {
			auto [tot, w, times] = q.top();
			q.pop();
			ll y = w / 2;
			sum -= tot;
			q.emplace(((y + 1) / 2) * times, y, times);
			ans++;
		}
		cout << ans << endl;
	}
	return 0;
}

