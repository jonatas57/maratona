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
	vector<list<int>> adj;
	vi deg;
	graph(int n) : size(n) {
		adj.resize(n);
		deg.resize(n, 0);
	}
	void addEdge(int a, int b) {
		adj[a].push_back(b);
		adj[b].push_back(a);
		deg[a]++;
		deg[b]++;
	}
};

vb visit;
int height(graph& g, int u) {
	visit[u] = true;
	int h = 1;
	each(x, g.adj[u]) {
		if (!visit[u]) {
			h = max(h, height(g, x));
		}
	}
	return h;
}

int countbits(int x) {
	int c = 0;
	while (x) {
		c++;
		x -= x & -x;
	}
	return c;
}

int main() {	
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int h;
	cin >> h;
	int n = (1 << h) - 2;
	visit.assign(n, false);
	graph g(n);
	int a, b;
	loop(n - 1) {
		cin >> a >> b;
		g.addEdge(a - 1, b - 1);
	}
	vi cnt(5, 0);
	bool p = false;
	each(x, g.deg) {
		if (x < 5) cnt[x]++;
		else p = true;
	}
	int m = n >> 1;
	vi ans;
	int mask = ((cnt[1] < m) << 2) + ((cnt[2] == 0) << 1) + (cnt[3] < m - 2);
	if (countbits(mask) > 1 or p or cnt[4] > 1) {
		ans.clear();
	}
	else if (mask & 4) {
		loop(n) {
			if (g.deg[i] == 2) {
				if (h == height(g, i)) ans.push_back(i);
			}
		}
	}
	else if (mask & 2) {
		if (n == 2) ans = {0, 1};
		else {
			loop(n) {
				if (g.deg[i] == 3) {
					if (h == height(g, i)) ans.push_back(i);
				}
			}
		}
	}
	else {
		loop(n) if (g.deg[i] == 4) ans.push_back(i);
	}
	cout << ans.size() << endl;
	if (! ans.empty()) {
		each(x, ans) cout << x + 1 << " ";
		cout << endl;
	}
	return 0;
}
