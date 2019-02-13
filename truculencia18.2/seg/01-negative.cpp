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

vi st;
void build(vi& v, int id, int l, int r) {
	if (l == r) {
		st[id] = v[l];
	}
	else {
		int mid = avg(l, r);
		build(v, id << 1, l, mid);
		build(v, id << 1 | 1, mid + 1, r);
		st[id] = min(st[id << 1], st[id << 1 | 1]);
	}
}
int query(int id, int l, int r, int ql, int qr) {
	if (l > qr or r < ql) return INF;
	if (l >= ql and r <= qr) return st[id];
	int mid = avg(l, r);
	return min(query(id << 1, l, mid, ql, qr), query(id << 1 | 1, mid + 1, r, ql, qr));
			
}

int main() {
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;
	int n, q;
	loop (t) {
		cin >> n >> q;
		vi x(n);
		st.resize(4 * n + 10);
		loop(n) {
			cin >> x[i];
		}
		build(x, 1, 0, n - 1);
		cout << "Scenario #" << i + 1 << endl;
		loop(q) {
			int a, b;
			cin >> a >> b;
			cout << query(1, 0, n - 1, a - 1, b - 1) << endl;
		}
	}
	return 0;
}
