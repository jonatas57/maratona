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

#define L(x) x << 1
#define R(x) x << 1 | 1

const ll mod = 1000000007;
const ll N = 400000, T = 4 * N + 10;

vector<ll> st(T), lazy(T, 0);

void build(vi& v, int id, int l, int r) {
	if (l == r) st[id] = 1ll << v[l];
	else {
		int mid = avg(l, r);
		build(v, L(id), l, mid);
		build(v, R(id), mid + 1, r);
		st[id] = st[L(id)] | st[R(id)];
	}
}

void prop(int id, int l, int r) {
	if (lazy[id]) {
		st[id] = lazy[id];
		if (l != r) lazy[L(id)] = lazy[R(id)] = lazy[id];
		lazy[id] = 0;
	}
}

void update(int id, int l, int r, int a, int b, ll val) {
	prop(id, l, r);
	if (l > b or r < a) return;
	if (a <= l and r <= b) {
		lazy[id] = 1ll << val;
		prop(id, l, r);
	}
	else {
		int mid = avg(l, r);
		update(L(id), l, mid, a, b, val);
		update(R(id), mid + 1, r, a, b, val);
		st[id] = st[L(id)] | st[R(id)];
	}
}

ll query(int id, int l, int r, int a, int b) {
	prop(id, l, r);
	if (l > b or r < a) return 0;
	if (a <= l and r <= b) return st[id];
	int mid = avg(l, r);
	return query(L(id), l, mid, a, b) | query(R(id), mid + 1, r, a, b);
}

struct graph {
	int size;
	vector<list<int>> adj;
	graph(int n) : size(n), adj(n) {}
	void addEdge(int a, int b) {
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
};

vi first, last;
int prox = 0;

void linearize(graph& g, int u = 0, int p = -1) {
	first[u] = prox++;
	each(v, g.adj[u]) {
		if (v == p) continue;
		linearize(g, v, u);
	}
	last[u] = prox - 1;
}

int bitcount(ll x) {
	int ans = 0;
	while (x) {
		x -= x & -x;
		ans++;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vi aux(n), c(n);
	loop(n) cin >> aux[i];
	graph g(n);
	int a, b, op;
	loop(n - 1) {
		cin >> a >> b;
		g.addEdge(a - 1, b - 1);
	}
	first.resize(n);
	last.resize(n);
	linearize(g);
	loop(n) {
		c[first[i]] = aux[i];
	}
	build(c, 1, 0, n - 1);
	loop(m) {
		cin >> op >> a;
		if (op == 1) {
			cin >> b;
			update(1, 0, n - 1, first[a - 1], last[a - 1], b);
		}
		else {
			cout << bitcount(query(1, 0, n - 1, first[a - 1], last[a - 1])) << endl;
		}
	}
	return 0;
}

