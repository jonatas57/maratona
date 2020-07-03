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
		adj[b].push_back(a);
	}
};

ii path(graph& g, int x, int y) {
	vb visit(g.size, false);
	vi par(g.size, -1);
	queue<int> q;
	visit[x] = 1;
	q.push(x);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		each(v, g.adj[u]) {
			if (visit[v]) continue;
			visit[v] = true;
			par[v] = u;
			q.push(v);
		}
	}
	ii ans(0, par[y]);
	int p = y;
	while (p != -1) {
		if (par[p] == x) ans.first = p; 
		p = par[p];
	}
	return ans;
}

int countChild(graph& g, int u, int ign, int p = -1) {
	int cnt = 1;
	each(v, g.adj[u]) {
		if (v == ign or v == p) continue;
		cnt += countChild(g, v, -1, u);
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	ll n, x, y;
	cin >> n >> x >> y;
	x--, y--;
	graph g(n);
	loop(n - 1) {
		int a, b;
		cin >> a >> b;
		g.addEdge(a - 1, b - 1);
	}
	auto [f, b] = path(g, x, y);
	ll p = countChild(g, x, f);
	ll q = countChild(g, y, b);
	cout << n * (n - 1) - p * q << endl;
	return 0;
}

