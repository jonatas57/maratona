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

vi id, sz;
void init(int x) {
	id.resize(x);
	sz.resize(x, 1);
	loop(x) id[i] = i;
}
int find(int x) { return x == id[x] ? x : id[x] = find(id[x]); }
bool join(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	if (sz[a] > sz[b]) swap(a, b);
	id[a] = b;
	sz[b] += sz[a];
	return true;
}

struct graph {
	int size;
	vector<ii> adj;
	vi deg;
	graph(int n) : size(n), deg(n, 0) {}
	void addEdge(int a, int b) {
		adj.emplace_back(a, b);
		deg[a]++;
		deg[b]++;
	}
	void sortEdges() {
		for (auto& [k, v] : adj) {
			if (deg[k] < deg[v]) swap(k, v);
			else if (deg[k] == deg[v] and k < v) swap(k, v);
		}
		sort(iter(adj), [&](ii a, ii b) {
			return deg[a.first] == deg[b.first] ? a < b : deg[a.first] > deg[b.first];
		});
	}
};

vector<ii> kruskall(graph& g) {
	vector<ii> ans;
	init(g.size);
	for (auto& [u, v] : g.adj) {
		if (join(u, v)) {
			ans.emplace_back(u, v);
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	graph g(n);
	loop(m) {
		int u, v;
		cin >> u >> v;
		g.addEdge(u - 1, v - 1);
	}
	g.sortEdges();
	for (auto& [u, v] : kruskall(g)) {
		cout << u + 1 << " " << v + 1 << endl;
	}
	return 0;
}

