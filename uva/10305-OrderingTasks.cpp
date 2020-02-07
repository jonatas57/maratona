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
	vi deg;
	graph(int n) : size(n), adj(n), deg(n, 0) {}
	void addEdge(int a, int b) {
		adj[a].push_back(b);
		deg[b]++;
	}
};

vi topSort(graph& g) {
	vi ans;
	queue<int> q;
	loop(g.size) if (!g.deg[i]) q.push(i);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		each(v, g.adj[u]) {
			g.deg[v]--;
			if (!g.deg[v]) q.push(v);
		}
		ans.push_back(u);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, m;
	while (cin >> n >> m and n | m) {
		graph g(n);
		int a, b;
		loop(m) {
			cin >> a >> b;
			g.addEdge(a - 1, b - 1);
		}
		each(x, topSort(g)) {
			cout << x + 1 << " ";
		}
		cout << endl;
	}
	return 0;
}

