#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<ll>         vll;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define each(x, s)         for(auto& x : s)
#define ceach(x, s)        for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define pb                 push_back
#define T                  100000
#define N                  4 * T + 10
#define avg(x, y)          x + (y - x) / 2
#define left(x)            x << 1
#define right(x)           x << 1 | 1

ll st[N];
void build(vll& v, int id, int l, int r) {
	if (l == r) {
		st[id] = (v[l] > 0 ? 1 : (v[l] < 0 ? -1 : 0));
	}
	else {
		int mid = avg(l, r);
		build(v, left(id), l, mid);
		build(v, right(id), mid + 1, r);
		st[id] = st[left(id)] * st[right(id)];
	}
}
ll query(int id, int l, int r, int ql, int qr) {
	if (l > qr or r < ql) return 1;
	if (l >= ql and r <= qr) return st[id];
	int mid = avg(l, r);
	return query(left(id), l, mid, ql, qr) * query(right(id), mid + 1, r, ql, qr);
}
void update(int id, int l, int r, ll val, int pos) {
  if (l == r) {
    st[id] = (val > 0 ? 1 : (val < 0 ? -1 : 0));
  }
  else {
    int mid = avg(l, r);
    if (pos <= mid) {
      update(left(id), l, mid, val, pos);
    }
    else {
      update(right(id), mid + 1, r, val, pos);
    }
    st[id] = st[left(id)] * st[right(id)];
  }
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

  int n, k;
  while (cin >> n >> k) {
    vll x(n);
    loop (n) {
      cin >> x[i];
    }
    memset(st, 0, N);
    build(x, 1, 0, n - 1);

    char c;
    ll a, b;
    string s = "";
    loop(k) {
      cin >> c >> a >> b;
      if (c == 'C') {
        update(1, 0, n - 1, b, a - 1);
      }
      else {
        int q = query(1, 0, n - 1, a - 1, b - 1);
        s += (q > 0 ? '+' : (q < 0 ? '-' : '0'));
      }
    }
    cout << s << endl;
  }
	return 0;
}
