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
	vector<set<int>> adj;
	map<string, int> conv;
	vi deg, av;
	graph() : size(0) {}
	void addEdge(string s, string t) {
		int x = addNode(s);
		int y = addNode(t);
		if (adj[x].insert(y).second) deg[y]++;
	}
	int addNode(string s) {
		if (!conv[s]) {
			conv[s] = ++size;
			adj.emplace_back();
			deg.push_back(0);
			av.push_back(0);
		}
		return conv[s] - 1;
	}
};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	graph g;
	string u, v;
	while (cin >> u) {
		g.addNode(u);
		while (cin >> v and v != "0") {
			g.addEdge(v, u);
		}
		g.av[g.conv[u] - 1] = 1;
	}

	int ans = 0;
	queue<int> q;
	loop(g.size) {
		if (g.av[i] and g.deg[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		ans++;
		int x = q.front();
		q.pop();
		each(y, g.adj[x]) {
			g.deg[y]--;
			if (g.av[y] and g.deg[y] == 0) {
				q.push(y);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
