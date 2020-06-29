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
#define L(x)               x << 1
#define R(x)               x << 1 | 1

const ll mod = 1000000007;

const int N = 4 * 1e5 + 10;
vector<ii> st(N);
vi lazy(N);

ii join(ii a, ii b) {
	ii c = {a.first + b.first, a.second <= 0 ? b.second : (b.second <= 0 ? a.second : min(a.second, b.second))};
	return c;
}

void build(vi& v, int id, int l, int r) {
	lazy[id] = 0;
	if (l == r) {
		st[id] = {v[l] > 0, v[l]};
	}
	else {
		int mid = avg(l, r);
		build(v, L(id), l, mid);
		build(v, R(id), mid + 1, r);
		st[id] = join(st[L(id)], st[R(id)]);
	}
}

void prop(int id, int l, int r) {
	if (lazy[id] and st[id].second > 0) {
		st[id].second += lazy[id];
		if (l != r) {
			lazy[L(id)] += lazy[id];
			lazy[R(id)] += lazy[id];
			if (st[id].second <= 0) {
				int mid = avg(l, r);
				prop(L(id), l, mid);
				prop(R(id), mid + 1, r);
				st[id] = join(st[L(id)], st[R(id)]);
			}
		}
		else if (st[id].second <= 0) {
			st[id].first = 0;
		}
	}
	lazy[id] = 0;
}

void update(int id, int l, int r, int a, int b, int val) {
	prop(id, l, r);
	if (l > b or r < a or a > b) return;
	if (a <= l and r <= b) {
		lazy[id] += val;
		prop(id, l, r);
	}
	else {
		int mid = avg(l, r);
		update(L(id), l, mid, a, b, val);
		update(R(id), mid + 1, r, a, b, val);
		st[id] = join(st[L(id)], st[R(id)]);
	}
}

int query(int id, int l, int r, int a, int b) {
	prop(id, l, r);
	if (l > b or r < a or a > b) return 0;
	if (a <= l and r <= b) return st[id].first;
	int mid = avg(l, r);
	return query(L(id), l, mid, a, b) + query(R(id), mid + 1, r, a, b);
}

struct graph {
	int size;
	vector<list<int>> adj;
	graph(int n) : size(n), adj(n) {}
	void addEdge(int a, int b) {
		adj[a].push_back(b);
	}
};

int prox = 0;
void linearize(graph& g, vi& first, vi& last, int u = 0) {
	int id = prox++;
	first[u] = id;
	each(x, g.adj[u]) {
		linearize(g, first, last, x);
	}
	last[u] = prox - 1;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	vi first(n + 1), last(n + 1), aux(n + 1), hs(n + 1);
	graph g(n + 1);
	loop(n) {
		int s;
		cin >> aux[i + 1] >> s;
		g.addEdge(s, i + 1);
	}
	linearize(g, first, last);
	loop(n + 1) {
		hs[first[i]] = aux[i];
	}
	build(hs, 1, 0, n);
	int q, op, a, x;
	cin >> q;
	loop(q) {
		cin >> op >> a;
		if (op == 1) {
			cin >> x;
			update(1, 0, n, first[a] + 1, last[a], -x);
		}
		else {
			cout << query(1, 0, n, first[a] + 1, last[a]) << endl;
		}
	}
	return 0;
}

