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
#define endl               "\n"

struct graph {
	int size;
	vector<list<int>> adj;
	graph() : size(0) {}
	void addEdge(int a, int b) {
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	void addNode() {
		size++;
		adj.push_back(list<int>());
	}
};

int bfs(graph& g, int st, int en) {
	vb visit(g.size, false);
	vi dist(g.size, INF);
	queue<int> q;
	visit[st] = true;
	dist[st] = 0;
	q.push(st);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		each(v, g.adj[u]) {
			if (!visit[v]) {
				visit[v] = true;
				q.push(v);
				dist[v] = dist[u] + 1;
				if (v == en) return dist[en];
			}
		}
	}
}

bool path(char c) { return c != '#'; }

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<string> mapa(n);
	graph g;
	g.addNode();
	loop(n) {
		cin >> mapa[i];
	}
	vector<int> up(m, 0);
	int next = 1, p;
	loop(n) {
		int left = 0;
		vloop(j, m) {
			if (path(mapa[i][j])) {
				if (mapa[i][j] == 'P') p = next;
				bool u = i and path(mapa[i - 1][j]);
				bool d = i != n - 1 and path(mapa[i + 1][j]);
				bool l = j and path(mapa[i][j - 1]);
				bool r = j != m - 1 and path(mapa[i][j + 1]);
				if (((u or d) and (l or d)) or u + d + l + r == 1) {
					g.addNode();
					if (up[j] != -1) g.addEdge(up[j], next);
					if (left != -1) g.addEdge(left, next);
					up[j] = next;
					left = next;
					next++;
				}
				else up[j] = -1;
			}
			else {
				left = up[j] = -1;
			}
		}
		if (left != -1) g.addEdge(0, left);
	}
	each(x, up) if (x != -1) g.addEdge(0, x);
	cout << bfs(g, 0, p) << endl;
	return 0;
}

