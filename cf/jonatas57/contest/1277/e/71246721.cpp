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

vi id;
vector<ll> sz;
void init(int n) {
	id.resize(n);
	sz.assign(n, 1);
	loop(n) id[i] = i;
}
int find(int x) { return x == id[x] ? x : id[x] = find(id[x]); }
void join(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
	if (sz[a] > sz[b]) swap(a, b);
	id[a] = id[b];
	sz[b] += sz[a];
}

struct graph {
	int size;
	vector<list<int>> adj;
	vi cnt;
	graph(int n) : size(n), adj(n), cnt(n, 0) {}
	void addEdge(int a, int b) {
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
};

void bfs(graph& g, int a, int b) {
	vb visit(g.size, false);
	vi par(g.size, -1);
	queue<int> q;
	visit[a] = true;
	visit[b] = true;
	q.push(a);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		each(v, g.adj[u]) {
			if (visit[v]) continue;
			visit[v] = true;
			par[v] = u;
			q.push(v);
			g.cnt[v]++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		int n, m, a, b;
		cin >> n >> m >> a >> b;
		a--, b--;
		init(n);
		graph g(n);
		int u, v;
		loop(m) {
			cin >> u >> v;
			u--, v--;
			g.addEdge(u, v);
		}
		bfs(g, a, b);
		bfs(g, b, a);
		loop(n) {
			if (i == a or i == b or g.cnt[i] == 1) {
				each(v, g.adj[i]) {
					if (g.cnt[v] == 1) join(i, v);
				}
			}
		}
		cout << (sz[find(a)] - 1) * (sz[find(b)] - 1) << endl;
	}
	return 0;
}

