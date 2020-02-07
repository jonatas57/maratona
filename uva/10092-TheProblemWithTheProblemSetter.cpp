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
	vector<vi> adj;

	graph(int n) : size(n), adj(n, vi(n, 0)) {}
	void addEdge(int a, int b, int f) {
		adj[a][b] += f;
	}
};

vector<vi> bfs(graph& g, vector<vi>& f, int s, int t) {
	vi par(g.size, -1);
	queue<int> q;
	par[s] = s;
	q.push(s);
	vector<vi> paths;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vloop(v, g.size) {
			if (g.adj[u][v] - f[u][v] > 0 and par[v] == -1) {
				par[v] = u;
				q.push(v);
				if (t == v) {
					vi aux;
					do {
						aux.push_back(v);
						v = par[v];
					} while (v != aux.back());
					vi path(riter(aux));
					paths.push_back(path);
				}
			}
		}
	}
	return paths;
}

pair<int, vector<vi>> flow(graph& g, int s, int t) {
	int n = g.size;
	vector<vi> f(n, vi(n, 0));
	vector<vi> paths;
	while (!(paths = bfs(g, f, s, t)).empty()) {
		each(path, paths) {
			int flow = INF, u, v, l = path.size();
			loop(l - 1) {
				u = path[i];
				v = path[i + 1];
				flow = min(flow, g.adj[u][v] - f[u][v]);
			}
			loop(l - 1) {
				u = path[i];
				v = path[i + 1];
				f[u][v] += flow;
				f[v][u] -= flow;
			}
		}
	}
	int sum = 0;
	loop(n) sum += f[s][i];
	return make_pair(sum, f);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int k, p;
	while (cin >> k >> p and k | p) {
		graph g(k + p + 2);
		int x, s = 0, t = k + p + 1, sum = 0;
		loop(k) {
			cin >> x;
			sum += x;
			g.addEdge(p + i + 1, t, x);
		}
		loop(p) {
			cin >> x;
			int c;
			g.addEdge(s, i + 1, 1);
			vloop(j, x) {
				cin >> c;
				g.addEdge(i + 1, p + c, 1);
			}
		}
		vector<vi> f;
		int ans;
		tie(ans, f) = flow(g, 0, k + p + 1);
		if (ans == sum) {
			cout << 1 << endl;
			for (int i = p + 1;i <= p + k;i++) {
				for (int j = 1;j <= p;j++) {
					if (f[i][j] < 0) cout << j << " ";
				}
				cout << endl;
			}
		}
		else cout << 0 << endl;
	}
	return 0;
}

