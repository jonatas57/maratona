#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef vector<bool>       vb;
typedef pair<int, int>     ii;

const int INF = 0x3f3f3f3f;
const ll  INFLL = 0x3f3f3f3f3f3f3f3fll;
const ll mod = 1000000007;

#define each(x, s)  for(auto& x : s)
#define loop(x)     for(int i = 0;i < x;i++)
#define vloop(v, x) for(int v = 0;v < x;v++)
#define iter(a)     a.begin(), a.end()
#define riter(a)    a.rbegin(), a.rend()
#define endl        "\n"
#define avg(l, r)   (l + r) / 2

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

vector<ll> fatDP(300001, -1);

ll fat(ll n) {
  if (n <= 1) return 1;
  if (fatDP[n] == -1) {
    fatDP[n] = n * fat(n - 1);
    fatDP[n] %= mod;
  }
  return fatDP[n];
}



int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    ll n, k;
    cin >> n >> k;
    loop(k) {
      int a, b;
      cin >> a >> b;
      n -= 1 + (a != b);
    }
    ll ans = 0;
    ll s = n & 1, d = n - s;
    ll c = s ? n : 1;
    while (d >= 0) {
      ll x = fat(d) * inv(fat((d + 1) / 2)) % mod;
      ans += x * c % mod;
      ans %= mod;

      c *= d * (d - 1) % mod;
      c %= mod;
      c *= inv((s + 1) * (s + 2) % mod);
      c %= mod;
      d -= 2;
      s += 2;
    }
    cout << ans << endl;
  }
  return 0;
}

