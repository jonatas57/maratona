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

pair<ll, ll> eucl(ll a, ll b) {
  if (!b) return {1, 0};
  auto [x, y] = eucl(b, a % b);
  return {y, x - a / b * y};
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  ll n, m;
  cin >> n >> m;
  ll g = gcd(n, m);
  ll ans = lcm(n, m);
  if ((n == 1) ^ (m == 1)) ans = 2;
  else if (g == 1) {
    auto [a, b] = eucl(n, m);
    if (a < 0) {
      ll t = abs(a) / m + 1;
      a += t * m;
      b -= t * n;
    }
    ans = min(ans, max(a * n, b * m));
    ll t = abs(b) / n + 1;
    a -= t * m;
    b += t * n;
    ans = min(ans, max(a * n, b * m));
  }
  cout << ans << endl;
  return 0;
}

