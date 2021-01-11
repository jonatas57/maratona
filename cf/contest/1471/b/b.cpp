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

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    loop(n) cin >> a[i];
    vector<ll> xps(n, 1);
    loop(n) {
      for (ll y = a[i];y % x == 0;y /= x, xps[i]++);
    }
    for (int i = 1;i < n;i++) xps[i] = min(xps[i], xps[i - 1]);
    ll m = xps.back();
    for (int i = n - 2;i >= 0;i--) xps[i] = min(xps[i], m + 1);
    ll ans = 0;
    loop(n) ans += xps[i] * a[i];
    cout << ans << endl;
  }
  return 0;
}

