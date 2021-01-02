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

ll comb(ll x) {
  return x * x % mod;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n;
    cin >> n;
    vi cnt(60, 0);
    vector<ll> a(n);
    loop(n) {
      cin >> a[i];
      for (ll j = 0, m = 1;j < 60;j++, m <<= 1) {
        if (a[i] & m) cnt[j]++;
      }
    }
    ll ans = 0;
    each(x, a) {
      ll e = 0, ou = 0;
      for (ll i = 0, m = 1;i < 60;i++, m <<= 1) {
        ll m2 = m % mod;
        if (x & m) {
          e += m2 * cnt[i] % mod;
          ou += m2 * n % mod;
        }
        else {
          ou += m2 * cnt[i] % mod;
        }
      }
      e %= mod;
      ou %= mod;
      ans = (ans + e * ou % mod) % mod;
    }
    cout << ans << endl;
  }
  return 0;
}

