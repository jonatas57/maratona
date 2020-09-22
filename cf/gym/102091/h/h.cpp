#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
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

ll xp(ll b, ll e, ll mod = ULLONG_MAX) {
  if (e == 0) return 1;
  ll c = xp(b, e >> 1, mod);
  c = c * c % mod;
  if (e & 1) c = c * b % mod;
  return c;
}

ll tot(ll x) {
  ll ans = 1;
  for (ll i = 2;i * i <= x;i++) {
    ll cnt = 0;
    while (x % i == 0) {
      x /= i;
      cnt++;
    }
    if (cnt) {
      ans *= xp(i, cnt) - xp(i, cnt - 1);
    }
  }
  if (x > 1) ans *= x - 1;
  return ans;
}

ll inv(ll x, ll mod) {
  return xp(x, tot(mod) - 1, mod);
}

ll chinese(vector<pair<ll, ll>>& mods) {
  __int128 N = 1;
  each(p, mods) N *= p.second;
  vector<ll> y;
  __int128 ans = 0;
  for (auto& [a, mod] : mods) {
    __int128 x = (N / mod) * a % N;
    x = x * inv(N / mod, mod) % N;
    ans += x;
    ans %= N;
  }
  return (ll)ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    vector<pair<ll, ll>> mods(3);
    loop(3) cin >> mods[i].second;
    loop(3) cin >> mods[i].first;
    ll x3 = round(pow(chinese(mods), 1.0 / 3));
    cout << x3 << endl;
  }
  return 0;
}

