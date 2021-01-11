#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>         vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define INFLL              0x3f3f3f3f3f3f3f3f
#define each(x, s)         for(auto& x : s)
#define loop(x)            for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

const ll mod = 1000000007;
const double EPS = 1e-7;
const double PI = acos(-1);

struct segtree {
  int size;
  vi st;

  segtree(int n) : size(n), st(4 * n + 10) {}
  segtree(vi& v) : segtree(v.size()) {
    build(v, 1, 0, size - 1);
  }

  void build(vi& v, int id, int l, int r) {
    if (l == r) st[id] = v[l];
    else {
      int mid = avg(l, r);
      build(v, id << 1, l, mid);
      build(v, id << 1 | 1, mid + 1, r);
      st[id] = st[id << 1] xor st[id << 1 | 1];
    }
  }

  void update(int id, int l, int r, int pos, int val) {
    if (l == r) st[id] ^= val;
    else {
      int mid = avg(l, r);
      if (mid >= pos) update(id << 1, l, mid, pos, val);
      else update(id << 1 | 1, mid + 1, r, pos, val);
      st[id] = st[id << 1] xor st[id << 1 | 1];
    }
  }

  int query(int id, int l, int r, int a, int b) {
    if (l > b or r < a) return 0;
    if (a <= l and r <= b) return st[id];
    int mid = avg(l, r);
    return query(id << 1, l, mid, a, b) xor query(id << 1 | 1, mid + 1, r, a, b);
  }

  void update(int pos, int x) {
    update(1, 0, size - 1, pos, x);
  }

  int query(int l, int r) {
    return query(1, 0, size - 1, l, r);
  }
};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n, q;
  cin >> n >> q;
  vi a(n);
  loop(n) cin >> a[i];
  segtree st(a);
  loop(q) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 1) st.update(x - 1, y);
    else cout << st.query(x - 1, y - 1) << endl;
  }
  return 0;
}

