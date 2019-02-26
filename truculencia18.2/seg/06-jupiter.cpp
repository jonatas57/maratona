#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define T                  100000
#define N                  4 * T + 10
#define each(x, s)         for(auto& x : s)
#define ceach(x, s)        for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define pb                 push_back
#define avg(x, y)          x + (y - x) / 2
#define left(x)            x << 1
#define right(x)           x << 1 | 1

ll MOD, B;
typedef pair<ll, int>      lli;
lli st[N];
bool ready[N];
ll powers[N];

ll power(ll x, int a) {
	if (ready[a]) return powers[a];
	if (a == 1) return x;
	ll c = power(x, a / 2);
	c *= c;
	c %= MOD;
	if (a & 1) {
		c *= x;
		c %= MOD;
	}
	return powers[a] = c;
}
lli operator+(lli a, lli b) {
	return {(a.first * power(B, b.second) + b.first) % MOD, a.second + b.second};
}

void build(int id, int l, int r) {
	if (l == r) {
		st[id] = {0, 1};
	}
	else {
		int mid = avg(l, r);
		build(left(id), l, mid);
		build(right(id), mid + 1, r);
		st[id] = st[left(id)] + st[right(id)];
	}
}
lli query(int id, int l, int r, int ql, int qr) {
	if (l > qr or r < ql) return {0, 0};
	if (l >= ql and r <= qr) return st[id];
	int mid = avg(l, r);
	return query(left(id), l, mid, ql, qr) + query(right(id), mid + 1, r, ql, qr);
}
void update(int id, int l, int r, int pos, int v) {
	if (l == r) {
		st[id].first = v;
	}
	else {
    int mid = avg(l, r);
		if (mid >= pos) {
   		update(left(id), l, mid, pos, v);
		}
		else {
    	update(right(id), mid + 1, r, pos, v);
		}
    st[id] = st[left(id)] + st[right(id)];
  }
}

int main() {
	ios_base::sync_with_stdio(false);

	ready[0] = true, powers[0] = 1;
	ll l, n;
	while (cin >> B >> MOD >> l >> n && (B != 0 || MOD != 0 || l != 0 || n != 0)) {
		build(1, 0, l - 1);
		char o;
		int a, b;
		loop(n) {
			cin >> o >> a >> b;
			if (o == 'E') {
				update(1, 0, l - 1, a - 1, b);
			}
			else {
				cout << query(1, 0, l - 1, a - 1, b - 1).first << endl;
			}
		}
		cout << "-\n";
	}
	return 0;
}
