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
	map<int, list<int>> adj;
	void addEdge(int a, int b) {
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int size() { return adj.size(); }
};

int bfs(graph& g, int u, int ttl) {
	int n = g.size();
	map<int, bool> visit;
	queue<ii> q;
	try {
		g.adj.at(u);
		visit[u] = true;
	}
	catch (...) {
		return n;
	}
	n--;
	q.emplace(u, ttl);
	while (!q.empty()) {
		tie(u, ttl) = q.front();
		q.pop();
		each(v, g.adj[u]) {
			if (visit[v] or !ttl) continue;
			n--;
			visit[v] = true;
			q.emplace(v, ttl - 1);
		}
	}
	return n;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, c = 1;
	while (cin >> n and n) {
		graph g;
		int a, b;
		loop(n) cin >> a >> b, g.addEdge(a, b);
		while (cin >> a >> b and a | b) {
			cout << "Case " << c++ << ": " << bfs(g, a, b) << " nodes not reachable from node " << a << " with TTL = " << b << "." << endl;
		}
	}
	return 0;
}

