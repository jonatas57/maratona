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
#define avg(l, r)          (l + r) >> 1
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

const ll mod = 998244353;
const double EPS = 1e-7;
const double PI = acos(-1);

vector<ll> dp(200001, -1);

ll fat(int x) {
  if (dp[x] == -1) {
    if (x < 2) dp[x] = 1;
    else dp[x] = x * fat(x - 1) % mod;
  }
  return dp[x];
}

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
  if (k > n / 2) k = n - k;
  ll a = 1, b = 1;
  loop(k) {
    a = a * (n - i) % mod;
    b = b * (i + 1) % mod;
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
    vi a(n);
    mii cnt;
    loop(n) cin >> a[i], cnt[a[i]]++;
    sort(iter(a));
    if (a[n - 1] == a[n - 2]) cout << fat(n) << endl;
    else if (a[n - 1] > a[n - 2] + 1) cout << 0 << endl;
    else {
      int x = cnt[a[n - 2]];
      ll tot = fat(n);
      ll rem = fat(x) * fat(n - x - 1) % mod * choose(n, x + 1) % mod;
      cout << (tot - rem + mod) % mod << endl;
    }
  }
  return 0;
}

