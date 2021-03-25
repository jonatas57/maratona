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

typedef tuple<int, int, int> tup;
struct segtree {
  int size;
  vector<tup> st;
  bool maxi;

  tup join(tup a, tup b) {
    return maxi ? max(a, b) : min(a, b);
  }

  segtree(int n, bool maxi) : size(n), st(4 * n + 10), maxi(maxi) {}
  segtree(vector<ii>& v, bool maxi) : segtree(v.size(), maxi) {
    build(v, 1, 0, size - 1);
  }

  void build(vector<ii>& v, int id, int l, int r) {
    if (l == r) st[id] = {v[l].second, v[l].first, l};
    else {
      int mid = avg(l, r);
      build(v, id << 1, l, mid);
      build(v, id << 1 | 1, mid + 1, r);
      st[id] = join(st[id << 1], st[id << 1 | 1]);
    }
  }

  void update(int id, int l, int r, int pos) {
    if (l == r) {
      get<0>(st[id])--;
      if (get<0>(st[id]) == 0) st[id] = maxi ? make_tuple(-1, -1, -1) : make_tuple(INF, INF, INF);
    }
    else {
      int mid = avg(l, r);
      if (pos <= mid) update(id << 1, l, mid, pos);
      else            update(id << 1 | 1, mid + 1, r, pos);
      st[id] = join(st[id << 1], st[id << 1 | 1]);
    }
  }

  tup query(int id, int l, int r, int a, int b) {
    if (l > b or r < a) return maxi ? make_tuple(0, 0, 0) : make_tuple(INF, INF, INF);
    if (a <= l and r <= b) return st[id];
    int mid = avg(l, r);
    return join(query(id << 1, l, mid, a, b), query(id << 1 | 1, mid + 1, r, a, b));
  }

  void update(int pos) {
    update(1, 0, size - 1, pos);
  }

  int query() {
    return get<2>(query(1, 0, size - 1, 0, size - 1));
  }
};


int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n;
    cin >> n;
    mii a;
    int z;
    loop(n) {
      cin >> z;
      a[z]++;
    }
    vector<ii> b(iter(a));
    segtree mx(b, true), mn(b, false);
    int ans = n;
    while (true) {
      int x = mx.query(), y = mn.query();
      if (x == y or x < 0 or x == INF or y < 0 or y == INF) break;
      mx.update(x), mn.update(x);
      mx.update(y), mn.update(y);
      ans -= 2;
    }
    cout << ans << endl;
  }
  return 0;
}

