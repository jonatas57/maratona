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

vi id, sz;
void init(int x) {
	id.resize(x);
	sz.resize(x, 1);
	loop(x) id[i] = i;
}

int find(int x) { return x == id[x] ? x : id[x] = find(id[x]); }

void join(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (a > b) swap(a, b);
	id[a] = b;
	sz[b] += sz[a];
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	graph g(n + m);
	vector<string> ss(n);
	init(n + m);
	loop(n) {
		cin >> ss[i];
		vloop(j, m) {
			if (ss[i][j] == '=') join(i, n + j);
		}
	}
	bool p = true;
	loop(n) {
		vloop(j, m) {
			int a = find(i), b = find(n + j);
			if (a == b and ss[i][j] != '=') {
				p = false;
				break;
			}
			if (ss[i][j] == '<') g.addEdge(a, b);
			else if (ss[i][j] == '>') g.addEdge(b, a);
		}
	}
	vi ans(n + m, -1);
	if (p) {
		queue<int> q;
		vb visit(n + m, false);
		loop(n + m) if (!g.deg[i]) q.push(i), ans[i] = 1;
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			visit[u] = true;
			each(v, g.adj[u]) {
				if (visit[v]) {
					p = false;
					break;
				}
				g.deg[v]--;
				if (!g.deg[v]) {
					q.push(v);
					ans[v] = ans[u] + 1;
				}
			}
		}
		loop(n + m) {
			ans[i] = ans[find(i)];
			if (ans[i] == -1) p = false;
		}
	}
	if (p) {
		cout << "Yes" << endl;
		loop(n) cout << ans[i] << " ";
		cout << endl;
		loop(m) cout << ans[n + i] << " ";
		cout << endl;
	}
	else cout << "No" << endl;
	return 0;
}

