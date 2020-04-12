#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define MAX                100000
#define N                  4 * MAX + 10
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define ceach(x, s)        for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2

bool inc(vi& v, int p, int m) {
	if (p == m) return false;
	v[p]++;
	if (v[p] == 7) {
		v[p] = 1;
		return inc(v, p + 1, m);
	}
	return true;
}

struct graph {
	int n;
	vector<list<int>> adj;
	vi val, deg;
	graph(int n) : n(n) {
		adj.resize(n);
		val.resize(n, 1);
		deg.resize(n, 0);
	}
	void addEdge(int a, int b) {
		adj[a].push_back(b);
		deg[a]++;
		deg[b]++;
	}
	int eval() {
		int ans = 0;
		vector<vb> used;
		while (inc(val, 0, n)) {
			used.assign(7, vb(7, false));
			int cnt = 0;
			loop(n) {
				each(j, adj[i]) {
					int x = val[i], y = val[j];
					if (!used[x][y] and !used[y][x]) {
						used[x][y] = used[y][x] = true;
						cnt++;
					}
				}
			}
			ans = max(ans, cnt);
		}
		return ans;
	}
};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	graph g(n);
	loop(m) {
		int a, b;
		cin >> a >> b;
		g.addEdge(a - 1, b - 1);
	}
	if (m) cout << g.eval() << endl;
	else cout << 0 << endl;
	return 0;
}


