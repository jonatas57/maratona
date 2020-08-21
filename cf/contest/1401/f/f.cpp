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

const int N = 4 * (1 << 18) + 10;
vector<ll> st(N);
vi L(N), R(N);
vb inv(20, false), sw(20, false);

void build(vi& v, int id, int l, int r) {
	if (l == r) {
		st[id] = v[l];
	}
	else {
		int mid = avg(l, r);
		L[id] = id << 1;
		R[id] = id << 1 | 1;
		build(v, L[id], l, mid);
		build(v, R[id], mid + 1, r);
		st[id] = st[L[id]] + st[R[id]];
	}
}

ll sum(int id, int l, int r, int a, int b, int h = 0) {
	if (inv[h]) {
		swap(a, b);
		a = l + r - a;
		b = l + r - b;
	}
	if (r < a or l > b) return 0;
	if (a <= l and r <= b) return st[id];
	int mid = avg(l, r);
	return sum(sw[h] ? R[id] : L[id], l, mid, a, b, h + 1) + sum(sw[h] ? L[id] : R[id], mid + 1, r, a, b, h + 1);
}

void update(int id, int l, int r, int pos, int val, int h = 0) {
	if (inv[h]) {
		pos = l + r - pos;
	}
	if (l == r) {
		st[id] = val;
	}
	else {
		int mid = avg(l, r);
		if (pos <= mid) update(sw[h] ? R[id] : L[id], l, mid, pos, val, h + 1);
		else update(sw[h] ? L[id] : R[id], mid + 1, r, pos, val, h + 1);
		st[id] = st[L[id]] + st[R[id]];
	}
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int e, q;
	cin >> e >> q;
	int n = 1 << e;
	vi a(n);
	loop(n) cin >> a[i];
	build(a, 1, 0, n - 1);
	int op, x, k;
	loop(q) {
		cin >> op >> x;
		if (op == 1) {
			cin >> k;
			update(1, 0, n - 1, x - 1, k);
		}
		else if (op == 2) {
			inv[e - x] = !inv[e - x];
		}
		else if (op == 3) {
			sw[e - x - 1] = !sw[e - x - 1];
		}
		else {
			cin >> k;
			cout << sum(1, 0, n - 1, x - 1, k - 1) << endl;
		}
	}
	return 0;
}

