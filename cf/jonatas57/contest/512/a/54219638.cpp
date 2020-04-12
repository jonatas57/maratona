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
	vi deg;

	graph(int n) : size(n) {
		adj.resize(n);
		deg.resize(n, 0);
	}
	void addEdge(int a, int b) {
		if (adj[a][b]) return;
		deg[b]++;
		adj[a][b] = true;
	}
};

vi topSort(graph& g) {
	queue<int> q;
	vi ans(1, 0);
	loop(g.size) {
		if (g.deg[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		ans[0]++;
		each(p, g.adj[x]) {
			if (!--g.deg[p.first]) {
				q.push(p.first);
			}
		}
		ans.push_back(x);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	string s, t;
	graph g(26);
	cin >> s;
	bool p = true;
	loop(n - 1) {
		cin >> t;
		for (int i = 0;;i++) {
			if (s[i] != '\0' && t[i] == '\0') p = false;
			if (s[i] == '\0' || t[i] == '\0') break;
			else if (s[i] != t[i]) {
				g.addEdge(s[i] - 'a', t[i] - 'a');
				break;
			}
		}
		s = t;
	}
	vi ans = topSort(g);
	if (p && ans[0] == 26) {
		rep(1, 27, 1) {
			cout << (char)(ans[i] + 'a');
		}
		cout << endl;
	}
	else cout << "Impossible\n";
	return 0;
}

