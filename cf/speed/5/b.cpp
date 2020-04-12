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

struct graph {
	int size;
	vector<list<int>> adj;
	graph(int n) : size(n) {
		adj.resize(n);
	}
	void addEdge(int a, int b, bool und) {
		adj[a].push_back(b);
		if (und) adj[b].push_back(a);
	}
};

int bfs(graph& g, int st, int end) {
	vb vis(g.size, false);
	vi dist(g.size, INF);
	queue<int> q;
	vis[st] = true;
	dist[st] = 0;
	q.push(st);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		each(v, g.adj[u]) {
			if (!vis[v]) {
				vis[v] = true;
				dist[v] = dist[u] + 1;
				q.push(v);
			}
			if (v == end) return dist[end];
		}
	}
	return INF;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, sum = 0;
	cin >> n;
	vi a(n + 1, 0);
	loop(n) cin >> a[i + 1], sum += ++a[i + 1];
	graph g(sum);
	int v = 0, acc = 0;
	loop(n) {
		vloop(j, a[i + 1]) {
			if (i) g.addEdge(v, acc + min(j, a[i] - 1), j < a[i]);
			if (j) g.addEdge(v, v - 1, true);
			v++;
		}
		for (int j = a[i + 1];j < a[i];j++) {
			g.addEdge(acc + j, v - 1, false);
		}
		acc += a[i];
	}
	loop(n) a[i + 1] += a[i]; 
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	int st = a[r1 - 1] + c1 - 1, end = a[r2 - 1] + c2 - 1;
	cout << bfs(g, st, end) << endl;
	return 0;
}
