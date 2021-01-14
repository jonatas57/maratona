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
  vector<ii> st;

  segtree(int n) : size(n), st(4 * n + 10) {}
  segtree(vi& v) : segtree(v.size()) {
    build(v, 1, 0, size - 1);
  }

  ii join(ii a, ii b) {
    return make_pair(min(a.first, b.first), max(a.second, b.second));
  }

  void build(vi& v, int id, int l, int r) {
    if (l == r) st[id] = {v[l], v[l]};
    else {
      int mid = avg(l, r);
      build(v, id << 1, l, mid);
      build(v, id << 1 | 1, mid + 1, r);
      st[id] = join(st[id << 1], st[id << 1 | 1]);
    }
  }

  ii query(int id, int l, int r, int a, int b) {
    if (l > b or r < a) return {INF, -INF};
    if (a <= l and r <= b) return st[id];
    int mid = avg(l, r);
    return join(query(id << 1, l, mid, a, b), query(id << 1 | 1, mid + 1, r, a, b));
  }

  ii query(int l, int r) {
    return query(1, 0, size - 1, l, r);
  }
};


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n, m;
    string s;
    cin >> n >> m >> s;
    vi del(n + 1, 0);
    for (int i = 0;s[i];i++) {
      del[i + 1] = del[i] + (s[i] == '-' ? -1 : 1);
    }
    segtree st(del);
    int l, r;
    loop(m) {
      cin >> l >> r;
      int high = 0, low = 0;
      int lastl = del[l - 1], lastr = del[r];
      auto [x, y] = st.query(0, l - 1);
      high = max(high, y);
      low = min(low, x);
      if (r < n) {
        tie(x, y) = st.query(r + 1, n);
        high = max(high, lastl + y - lastr);
        low = min(low, lastl + x - lastr);
      }
      cout << high - low + 1 << endl;
    }
  }
  return 0;
}
