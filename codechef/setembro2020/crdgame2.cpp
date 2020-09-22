#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define INFLL              0x3f3f3f3f3f3f3f3f
#define each(x, s)         for(auto& x : s)
#define loop(x)	           for(int i = 0;i < x;i++)
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
  return xp(x, mod - 2);
}

ll choose(ll n, ll k) {
  ll a = 1, b = 1;
  loop(k) {
    a *= n - i;
    b *= i + 1;
    a %= mod;
    b %= mod;
  }
  return a * inv(b) % mod;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n;
    cin >> n;
    mii cnt;
    int x;
    loop(n) cin >> x, cnt[x]++;
    int m = cnt.rbegin()->second;
    ll ans = xp(2, n);
    if (~m & 1) {
      ans -= choose(m, m / 2) * xp(2, n - m) % mod;
      if (ans < 0) ans += mod;
    }
    cout << ans << endl;
  }
	return 0;
}

