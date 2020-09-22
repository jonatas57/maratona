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

ll xp(ll b, ll e, ll mod) {
  if (e == 0) return 1;
  ll c = xp(b, e >> 1, mod);
  c = c * c % mod;
  if (e & 1) c = c * b % mod;
  return c;
}

ll inv(ll x, ll mod) {
  return xp(x, mod - 2, mod);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  ll n, k, q;
  cin >> n >> k >> q;
  ll c, d;
  ll invk = inv(k, n);
  loop(q) {
    cin >> c >> d;
    ll pos = d * invk % n;
    ll ans = c / n + (c % n >= pos + 1);
    cout << ans << endl;
  }
  return 0;
}

