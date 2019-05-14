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

struct graph {
	int size;
	vector<list<int>> adj;
	vi deg;

	graph(int n) : size(n) {
		adj.resize(n);
		deg.resize(n, 0);
	}
	void addEdge(int a, int b) {
		adj[a].push_front(b);
		deg[b]++;
	}
};

vi visit;
vb fallen, fprev;
int ans;

bool dfs(graph& g, int x, int v) {
	visit[x] = v;
	each(y, g.adj[x]) {
		if (visit[y] == -1) {
			bool p = dfs(g, y, v);
			fprev[x] = fprev[x] || p;
		}
		else if (fallen[y] && v == y) fprev[x] = true;
		else if (fprev[y] && fallen[visit[y]]) {
			fallen[visit[y]] = false;
			ans--;
		}
	}
	return fprev[x];
}

void fall(graph& g) {
	ans = 0;
	int n = g.size;
	visit.resize(n, -1);
	fallen.resize(n, false);
	fprev.resize(n, false);
	loop(n) {
		if (visit[i] == -1) {
			fallen[i] = fprev[i] = true;
			ans++;
			dfs(g, i, i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n, m, a, b;
		cin >> n >> m;
		graph g(n);
		loop(m) {
			cin >> a >> b;
			g.addEdge(a - 1, b - 1);
		}
		fall(g);
		cout << ans << endl;
		fallen.clear();
		fprev.clear();
		visit.clear();
	}
	return 0;
}

