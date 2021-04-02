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

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    ll n, k, m;
    cin >> n >> m >> k;
    vector<ll> choose(1, 1);
    for (ll i = m;i < n;i++) {
      ll x = choose.back() * i % mod;
      x = x * inv(i - m + 1) % mod;
      choose.push_back(x);
    }
    vi a(n);
    loop(n) cin >> a[i];
    sort(iter(a));
    ll ans = 0;
    for (int i = 0, j = 0;i < n;) {
      if (j < n and a[j] <= a[i] + k) j++;
      else {
        ll x = j - i - 1;
        ans += x < m - 1 ? 0 : choose[x - m + 1];
        i++;
        ans %= mod;
      }
    }
    cout << ans << endl;
  }
  return 0;
}

