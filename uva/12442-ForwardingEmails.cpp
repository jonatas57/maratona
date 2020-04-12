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
	}
};

vi ch;
int dfs(graph& g, int u) {
	if (ch[u] == -1) {
		ch[u] = 1;
		each(v, g.adj[u]) {
			ch[u] += dfs(g, v);
		}
	}
	return ch[u];
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		int n;
		cin >> n;
		graph g(n);
		int u, v;
		loop(n) {
			cin >> u >> v;
			g.addEdge(u - 1, v - 1);
		}
		ch.assign(n, -1);
		loop(n) {
			dfs(g, i);
		}
		int ans = 0, x = 0;
		loop(n) {
			if (ch[i] > x) {
				x = ch[i];
				ans = i;
			}
		}
		cout << "Case " << i + 1 << ": " << ans + 1 << endl;
	}
	return 0;
}

