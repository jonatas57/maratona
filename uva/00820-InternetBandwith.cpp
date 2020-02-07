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

	graph(int n) : size(n) {
		adj.resize(n, vi(n, 0));
	}
	void addEdge(int a, int b, int f) {
		adj[a][b] += f;
		adj[b][a] += f;
	}
};

vi bfs(vector<vi>& c, vector<vi>& f, int s, int t, int n) {
	vi p(n, -1);
	p[s] = s;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vloop(v, n) {
			if (c[u][v] - f[u][v] > 0 and p[v] == -1) {
				p[v] = u;
				q.push(v);
				if (v == t) {
					vi path;
					do {
						path.push_back(v);
						v = p[v];
					} while (v != path.back());
					vi ans(riter(path));
					return ans;
				}
			}
		}
	}
	return vi();
}

int edmondkarp(graph& g, int s, int t) {
	int n = g.size;
	vector<vi> F(n, vi(n, 0));
	while (true) {
		vi path = bfs(g.adj, F, s, t, n);
		if (path.empty()) break;
		int u, v, flow = INF;
		for (int i = 1;i < path.size();i++) {
			u = path[i - 1];
			v = path[i];
			flow = min(flow, g.adj[u][v] - F[u][v]);
		}
		for (int i = 1;i < path.size();i++) {
			u = path[i - 1];
			v = path[i];
			F[u][v] += flow;
			F[v][u] -= flow;
		}
	}
	int sum = 0;
	loop(n) {
		sum += F[s][i];
	}
	return sum;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	for (int i = 1;cin >> n and n;i++) {
		graph g(n);
		int s, t, c, a, b, f;
		cin >> s >> t >> c;
		loop(c) {
			cin >> a >> b >> f;
			g.addEdge(a - 1, b - 1, f);
		}
		cout << "Network " << i << endl;
		cout << "The bandwidth is " << edmondkarp(g, s - 1, t - 1) << "." << endl << endl;
	}
	return 0;
}

