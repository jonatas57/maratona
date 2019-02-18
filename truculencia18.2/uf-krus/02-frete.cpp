#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define each(x, s)         for(auto& x : s)
#define ceach(x, s)        for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define pb                 push_back

vi id, sz;
void makeset(int x) {
	id.clear(), sz.clear();
	id.resize(x), sz.resize(x, 1);
	loop(x) {
		id[i] = i;
	}
}
int find(int x) {
	if (x == id[x]) return x;
	return id[x] = find(id[x]);
}
void join(int x, int y) {
	int a = find(x), b = find(y);
	if (a == b) return;
	if (sz[a] > sz[b]) swap(a, b);
	id[a] = id[b];
	sz[b] += sz[a];
}

struct edge {
	int u, v, w;
	edge() {}
	edge(int u, int v, int w) : u(u), v(v), w(w) {}
};

bool comp(edge& e, edge& f) {
	return e.w < f.w;
}

int kruskal(vector<edge>& e, int n) {
	makeset(n);
	int ans = 0;
	each(x, e) {
		if (find(x.u) != find(x.v)) {
			join(x.u, x.v);
			ans += x.w;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	int n, m;
	cin >> n >> m;
	int a, b, w;
	vector<edge> edges(m);
	loop(m) {
		cin >> a >> b >> w;
		edges[i] = edge(min(a, b), max(a, b), w);
	}
	sort(edges.begin(), edges.end(), comp);
	int ans = kruskal(edges, n);
	cout << ans << endl;
	return 0;
}
