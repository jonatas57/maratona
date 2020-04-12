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
	vector<map<int, bool>> adj;
	vi deg, desc;

	graph(int n) : size(n) {
		adj.resize(n);
		deg.resize(n, 0);
		desc.resize(n, 0);
	}
	void addEdge(int a, int b) {
		adj[a][b] = true;
		deg[b]++;
		desc[a]++;
	}
};
vi cnt;
void cntDesc(graph& g, int root) {
	each(p, g.adj[root]) {
		if (p.second) {
			cntDesc(g, p.first);
			cnt[root] += cnt[p.first] + 1;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	int c, b;
	graph g(n);
	loop(n) {
		cin >> c;
		vloop(j, c) {
			cin >> b;
			g.addEdge(i, b - 1);
		}
	}
	queue<int> q;
	int t = 0, root;
	bool p = false;
	loop(n) if (g.deg[i] == 0) q.push(i), t++, root = i;
	vector<string> ans;
	if (t == 1) {
		p = true;
		while (!q.empty()) {
			int x = q.front();q.pop();
			each(p, g.adj[x]) {
				int y = p.first;
				if (!p.second) continue;
				g.deg[y]--;
				if (g.deg[y] == 0) {
					ans.push_back(to_string(x + 1) + " " + to_string(y + 1));
					q.push(y);
					t++;
				}
				else g.adj[x][y] = false;
			}
		}
		cnt.resize(n, 0);
		cntDesc(g, root);
		loop(n) {
			if (cnt[i] != g.desc[i]) p = false;
		}
	}
	if (t == n && p) {
		cout << "YES\n";
		each(s, ans) cout << s << endl;
	}
	else cout << "NO\n";
	return 0;
}

