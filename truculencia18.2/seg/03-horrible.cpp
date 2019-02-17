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

ll st[N], lazy[N];
void build(int id, int l, int r) {
	if (l == r) {
		st[id] = 0;
    lazy[id] = 0;
	}
	else {
		int mid = avg(l, r);
		build(left(id), l, mid);
		build(right(id), mid + 1, r);
		st[id] = st[left(id)] + st[right(id)];
    lazy[id] = 0;
	}
}
void prop(int id, int l, int r) {
  if (lazy[id]) {
    st[id] += lazy[id] * (r - l + 1);
    if (l != r) {
      lazy[left(id)] += lazy[id];
      lazy[right(id)] += lazy[id];
    }
    lazy[id] = 0;
  }
}
ll query(int id, int l, int r, int ql, int qr) {
  prop(id, l, r);
	if (l > qr or r < ql) return 0;
	if (l >= ql and r <= qr) return st[id];
	int mid = avg(l, r);
	return query(left(id), l, mid, ql, qr) + query(right(id), mid + 1, r, ql, qr);
}
void update(int id, int l, int r, int a, int b, int v) {
  prop(id, l, r);
  if (l > b or r < a) return;
	if (l >= a and r <= b) {
    lazy[id] = v;
    prop(id, l, r);
  }
	else {
    int mid = avg(l, r);
    update(left(id), l, mid, a, b, v);
    update(right(id), mid + 1, r, a, b, v);
    st[id] = st[left(id)] + st[right(id)];
  }
}

int main() {
	ios_base::sync_with_stdio(false);

  int t, n, c;
  cin >> t;
  loop (t) {
    cin >> n >> c;
    build(1, 0, n - 1);
    int o, p, q, v;
    loop(c) {
      cin >> o >> p >> q;
      if (o) {
        cout << query(1, 0, n - 1, p - 1, q - 1) << endl;
      }
      else {
        cin >> v;
        update(1, 0, n - 1, p - 1, q - 1, v);
      }
    }
  }
	return 0;
}
