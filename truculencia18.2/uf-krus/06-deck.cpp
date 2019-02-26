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
#define vloop(i, x)        for(int i = 0;i < x;i++)
#define pb                 push_back

#define N                  200010

int id[N], sz[N];
void makeset(int x) {
	x++;
	loop(x) {
		id[i] = i;
		sz[i] = 1;
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

vector<edge> kruskal(vector<edge>& e, int n, int m) {
	makeset(n);
	vector<edge> ans;
	for (int i = 0;i < m;i++) {
		edge x = e[i];
		if (find(x.u) != find(x.v)) {
			join(x.u, x.v);
			ans.pb(x);
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	
	int n, k;
	cin >> n;
	mii a;
	int aux;
	rep(1, n + 1, 1) {
		cin >> aux;
		a[aux] = i;
	}
	cin >> k;
	makeset(n);
	vloop(i, k) {
		vloop(j, n) {
			cin >> aux;
			join(aux, j + 1);
		}
	}
	int x;
	cin >> x;
	cout << (find(a[x]) == find(1) ? "YES" : "NO") << endl;
	return 0;
}
