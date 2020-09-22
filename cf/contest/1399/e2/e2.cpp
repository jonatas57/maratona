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

typedef tuple<int, ll, int, int> edge;
struct graph {
	int size;
	vector<list<edge>> adj;
	graph(int n) : size(n), adj(n) {}
	void addEdge(int a, int b, ll w, int c) {
		adj[a].emplace_back(b, w, 0, c);
		adj[b].emplace_back(a, w, 0, c);
	}
};

int dfs(graph& g, int u = 0, int p = -1) {
	bool leaf = true;
	int ch = 0;
	for (auto& [v, w, t, c] : g.adj[u]) {
		if (v == p) {
			t = -1;
			continue;
		}
		leaf = false;
		t += dfs(g, v, u);
		ch += t;
	}
	return ch + leaf;
}

struct op {
	ll w, times, del;
	op(ll w, ll t) : w(w), times(t), del((w + 1) / 2 * times) {}
	bool operator<(const op& o) const {
		return del == o.del ? w < o.w : del < o.del;
	}
};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int tc;
	cin >> tc;
	loop(tc) {
		int n, a, b, c;
		ll s, w;
		cin >> n >> s;
		graph g(n);
		loop(n - 1) {
			cin >> a >> b >> w >> c;
			g.addEdge(a - 1, b - 1, w, c);
		}
		dfs(g);
		priority_queue<op> q[2];
		ll sum = 0;
		loop(n) for (auto& [v, w, t, c] : g.adj[i]) {
			if (t == -1) continue;
			sum += w * t;
			q[c - 1].emplace(w, t);
		}
		vector<op> used;
		int ans = sum <= s ? 0 : INF, ans1 = 0;
		while (!q[0].empty()) {
			op o = q[0].top();
			q[0].pop();
			auto [w, tim, del] = o;

			sum -= del;
			ans1++;
			if (w > 1) q[0].emplace(w / 2, tim);
			if (sum <= s) ans = min(ans, ans1);

			used.push_back(o);
		}
		int ans2 = ans1;
		while (!q[1].empty()) {
			auto [w, tim, del] = q[1].top();
			q[1].pop();
			
			sum -= del;
			ans2 += 2;
			while (!used.empty() and used.back().del + sum <= s) {
				sum += used.back().del;
				ans2--;
				used.pop_back();
			}
			if (w > 1) q[1].emplace(w / 2, tim);
			if (sum <= s) ans = min(ans, ans2);
		}
		cout << ans << endl;
	}
	return 0;
}

