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

ll inv(ll m) {
  return xp(m, mod - 2);
}

ll calc(ll c, ll m) {
  if (m == 1) return c;
  ll ans = xp(c, m);
  ll rem = 0;
  for (int i = 1;i * i <= m;i++) {
    if (m % i) continue;
    rem += calc(c, i); 
    if (i > 1 and i * i != m) rem += calc(c, m / i);
    rem %= mod;
  }
  ans = (ans - rem + mod) % mod;
  return ans;
}

ll solve(int c, int m) {
  ll ans = 0;
  for (int i = 1;i * i <= m;i++) {
    if (m % i) continue;
    ans = (ans + calc(c, i) * inv(i)) % mod;
    if (i * i != m) ans = (ans + calc(c, m / i) * inv(m / i)) % mod;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n, m, c;
  cin >> n >> m >> c;
  cout << solve(xp(c, n * n), m) << endl;
  return 0;
}

