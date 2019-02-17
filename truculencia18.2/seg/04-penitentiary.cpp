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
#define avg(x, y)          x + (y - x) / 2
#define left(x)            x << 1
#define right(x)           x << 1 | 1

#define NULO ii(INF, 0)
#define IMPO ii(INF, -INF)

vector<ii> st;
ii overlap(ii x, ii y) {
	if (x == NULO) return y;
	if (y == NULO) return x;
	if (x == IMPO or y == IMPO) return IMPO;
	int lx, ly, rx, ry;
	tie(lx, rx) = x;
	tie(ly, ry) = y;
	if (lx > ry or rx < ly) return IMPO;
	return ii(max(lx, ly), min(rx, ry));
}
void build(vector<ii>& v, int id, int l, int r) {
	if (l == r) {
		st[id] = v[l];
	}
	else {
		int mid = avg(l, r);
		build(v, left(id), l, mid);
		build(v, right(id), mid + 1, r);
		st[id] = overlap(st[left(id)], st[right(id)]);
	}
}
void update(int id, int l, int r, int pos, ii val) {
	if (l == r) {
		st[id] = val;
	}
	else {
		int mid = avg(l, r);
		if (pos <= mid) {
			update(left(id), l, mid, pos, val);
		}
		else {
			update(right(id), mid + 1, r, pos, val);
		}
		st[id] = overlap(st[left(id)], st[right(id)]);
	}
}
ii query(int id, int l, int r, int a, int b) {
	if (l > b or r < a) return NULO;
	if (l >= a and r <= b) return st[id];
	int mid = avg(l, r);
	ii x = query(left(id), l, mid, a, b), y = query(right(id), mid + 1, r, a, b);
	return overlap(x, y);
}

int main() {
	int n, q;
	cin >> n >> q;
	vector<ii> g(n);
	loop(n) {
		int l, r;
		cin >> l >> r;
		g[i] = ii(l, r);
	}
	st.resize(4 * n + 10);
	build(g, 1, 0, n - 1);
	loop(q) {
		char o;
		int a, b, c;
		cin >> o >> a >> b;
		if (o == '?') {
			ii x = query(1, 0, n - 1, a - 1, b - 1);
			if (x == IMPO or x == NULO) cout << 0 << endl;
			else cout << x.second - x.first + 1 << endl;
		}
		else {
			cin >> c;
			update(1, 0, n - 1, a - 1, ii(b, c));
		}
	}
	return 0;
}
