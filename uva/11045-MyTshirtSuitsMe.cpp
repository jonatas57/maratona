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
	vector<vi> adj, f;

	graph(int n = 0) : size(n), adj(n, vi(n, 0)), f(n, vi(n, 0)) {}
	void addEdge(int a, int b, int c) {
		adj[a][b] = c;
	}
	int operator()(int a, int b) {
		return adj[a][b] - f[a][b];
	}
};

vi bfs(graph& g, int s, int t) {
	vi par(g.size, -1);
	queue<int> q;
	par[s] = s;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vloop(v, g.size) {
			if (g(u, v) > 0 and par[v] == -1) {
				par[v] = u;
				q.push(v);
				if (v == t) {
					vi aux;
					do {
						aux.push_back(v);
						v = par[v];
					} while (v != aux.back());
					vi path(riter(aux));
					return path;
				}
			}
		}
	}
	return {};
}

int flow(graph& g, int s, int t) {
	int maxflow = 0;
	vi path;
	while (!(path = bfs(g, s, t)).empty()) {
		int flow = INF, u, v, l = path.size();
		loop(l - 1) {
			u = path[i];
			v = path[i + 1];
			flow = min(flow, g(u, v));
		}
		loop(l - 1) {
			u = path[i];
			v = path[i + 1];
			g.f[u][v] += flow;
			g.f[v][u] -= flow;
		}
		maxflow += flow;
	}
	return maxflow;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int x;
	cin >> x;
	map<string, int> conv = {{"XXL", 1}, {"XL", 2}, {"L", 3}, {"M", 4}, {"S", 5}, {"XS", 6}};
	loop(x) {
		int n, m;
		cin >> n >> m;
		graph g(8 + m);
		loop(6) g.addEdge(0, i + 1, n / 6);
		string a, b;
		loop(m) {
			cin >> a >> b;
			g.addEdge(conv[a], i + 7, 1);
			g.addEdge(conv[b], i + 7, 1);
			g.addEdge(i + 7, 7 + m, 1);
		}
		cout << (m == flow(g, 0, 7 + m) ? "YES" : "NO") << endl;
	}
	return 0;
}

