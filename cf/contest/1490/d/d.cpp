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

  ii join(ii a, ii b) {
    return max(a, b);
  }

  segtree(int n) : size(n), st(4 * n + 10) {}
  segtree(vi& v) : segtree(v.size()) {
    build(v, 1, 0, size - 1);
  }

  void build(vi& v, int id, int l, int r) {
    if (l == r) st[id] = {v[l], l};
    else {
      int mid = avg(l, r);
      build(v, id << 1, l, mid);
      build(v, id << 1 | 1, mid + 1, r);
      st[id] = join(st[id << 1], st[id << 1 | 1]);
    }
  }

  ii query(int id, int l, int r, int a, int b) {
    if (l > b or r < a) return {-1, -1};
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
    int n;
    cin >> n;
    vi p(n);
    loop(n) cin >> p[i];
    segtree st(p);
    vi ans(n, -1);
    queue<tuple<int, int, int>> q;
    q.emplace(0, 0, n - 1);
    while (!q.empty()) {
      auto [x, l, r] = q.front();
      q.pop();
      auto [v, pos] = st.query(l, r);
      ans[pos] = x;
      if (l < pos) q.emplace(x + 1, l, pos - 1);
      if (pos < r) q.emplace(x + 1, pos + 1, r);
    }
    each(x, ans) cout << x << " ";
    cout << endl;
  }
  return 0;
}

