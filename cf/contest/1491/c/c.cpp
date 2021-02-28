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
  vector<ll> st;
  vector<ll> lazy;

  ll join(ll a, ll b) {
    return a + b;
  }

  segtree(int n) : size(n), st(4 * n + 10), lazy(4 * n + 10) {}

  void prop(int id, int l, int r) {
    if (lazy[id]) {
      st[id] += lazy[id];
      if (l != r) {
        lazy[id << 1] += lazy[id];
        lazy[id << 1 | 1] += lazy[id];
      }
      lazy[id] = 0;
    }
  }

  void update(int id, int l, int r, int a, int b, ll val) {
    prop(id, l, r);
    if (l > b or r < a) return;
    if (a <= l and r <= b) {
      lazy[id] = val;
      prop(id, l, r);
    }
    else {
      int mid = avg(l, r);
      update(id << 1, l, mid, a, b, val);
      update(id << 1 | 1, mid + 1, r, a, b, val);
      st[id] = join(st[id << 1], st[id << 1 | 1]);
    }
  }

  ll query(int id, int l, int r, int a, int b) {
    if (l > b or r < a) return 0;
    if (a <= l and r <= b) return st[id];
    int mid = avg(l, r);
    return join(query(id << 1, l, mid, a, b), query(id << 1 | 1, mid + 1, r, a, b));
  }

  void update(int l, int r, ll val) {
    update(1, 0, size - 1, l, r, val);
  }

  ll query(int l, int r) {
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
    vector<ll> a(n);
    loop(n) cin >> a[i];
    segtree st(n);
    ll ans = 0;
    loop(n) {
      ll x = a[i] - 1;
      ll p = st.query(i, i);
      if (p < x) p = x;
      int l = i + 2, r = i + a[i];
      if (r >= n) {
        ans += 1ll - n + r;
        r = n - 1;
        if (l > r) ans -= i == n - 1;
      }
      st.update(l, r, 1);
      if (p - x) {
        if (i == n - 1) ans += p - x;
        else st.update(i + 1, i + 1, p - x);
      }
    }
    cout << ans << endl;
  }
  return 0;
}

