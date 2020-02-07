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
	vector<mii> adj;

	graph(int n) : size(n), adj(n) {}
	void addEdge(int a, int b, int f) {
		adj[a][b] += f;
	}
	mii& operator[](int i) {
		return adj[i];
	}
};

vi bfs(graph& g, int s, int t, vector<vi>& f) {
	vi par(g.size, -1);
	queue<int> q;
	par[s] = s;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vloop(v, g.size) {
			int c = g[u][v];
			if (c - f[u][v] > 0 and par[v] == -1) {
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

pair<int, vector<vi>> edmond(graph& g, int s, int t) {
	int n = g.size;
	vector<vi> f(n, vi(n, 0));
	vi path;
	while (!(path = bfs(g, s, t, f)).empty()) {
		int flow = INF, u, v, l = path.size();
		loop(l - 1) {
			u = path[i];
			v = path[i + 1];
			flow = min(flow, g[u][v] - f[u][v]);
		}
		loop(l - 1) {
			u = path[i];
			v = path[i + 1];
			f[u][v] += flow;
			f[v][u] -= flow;
		}
	}
	int sum = 0;
	loop(n) sum += f[s][i];
	return {sum, f};
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	string s;
	bool p = true;
	while (p) {
		graph g(38); 
		int x = 0;
		for (int i = 1;i <= 10;i++) g.addEdge(0, i, 1);
		while (getline(cin, s)) {
			p = false;
			if (s.length()) {
				int j = s[0] - 'A' + 11, qtd = s[1] - '0';
				g.addEdge(j, 37, qtd);
				x += qtd;
				for (int i = 3;s[i] != ';';i++) {
					g.addEdge(s[i] - '0' + 1, j, 1);
				}
			}
			else {
				p = true;
				break;
			}
		}
		int flow;
		vector<vi> f;
		tie(flow, f) = edmond(g, 0, 37);
		string ans(10, '_');
		if (x == flow) {
			loop(10) {
				vloop(j, 26) {
					if (f[i + 1][j + 11] > 0) {
						ans[i] = 'A' + j;
						break;
					}
				}
			}
		}
		else ans = "!";
		cout << ans << endl;
	}
	return 0;
}

