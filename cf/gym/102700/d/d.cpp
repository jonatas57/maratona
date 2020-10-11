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

ll xp(ll b, ll e) {
  if (e == 0) return 1;
  ll c = xp(b, e >> 1);
  c = c * c % mod;
  if (e & 1) c = c * b % mod;
  return c;
}

ll inv(ll x) {
  return xp(x, mod - 2) % mod;
}

struct frac {
  ll n, d;
  frac(ll a = 0, ll b = 1) : n(a % mod), d(b % mod) {}
  void operator+=(frac&& f) {
    n = (n * f.d + d * f.n) % mod;
    d = d * f.d % mod;
  }
  frac operator*(frac& f) {
    return frac(n * f.n, d * f.d);
  }
  ll val() {
    return n * inv(d) % mod;
  }
};

struct poly {
  int deg;
  vector<frac> cs;
  poly(int d) : deg(d), cs(d, 0) {};
  poly operator*(poly& p) {
    poly q(deg);
    loop(deg) {
      vloop(j, deg) {
        q[i + j] += cs[i] * p[j];
      }
    }
    return q;
  }
  frac& operator[](int i) {
    return cs[i % deg];
  }
};

poly xp(poly& b, ll e) {
  if (e == 1) return b;
  poly c = xp(b, e >> 1);
  c = c * c;
  if (e & 1) c = c * b;
  return c;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n, m, k;
  cin >> n >> k >> m;
  poly p(m);
  for (int i = 1;i <= k;i++) {
    if (i % m == 0) continue;
    p[i] += frac(1, k - k / m);
  }
  poly ans = xp(p, n);
  cout << ans[0].val() << endl;
  return 0;
}

