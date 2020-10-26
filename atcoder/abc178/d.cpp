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

ll inv(ll b) {
  return xp(b, mod - 2);
}

ll choose(ll n, ll k) {
  if (k > n / 2) k = n - k;
  ll a = 1, b = 1;
  loop(k) {
    a = a * (n - i) % mod;
    b = b * (i + 1) % mod;
  }
  return a * inv(b) % mod;
}

ll solve(ll s, int n) {
  s -= 3 * n;
  if (s < 0) return 0;
  return choose(s + n - 1, n - 1);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int s;
  cin >> s;
  ll ans = 0;
  for (int i = 1;;i++) {
    ll x = solve(s, i);
    if (!x) break;
    ans += x;
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}

