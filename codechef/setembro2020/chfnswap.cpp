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
const double EPS = 1e-7;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    ll n;
    cin >> n;
    ll x = n * (n + 1) / 2;
    if (x & 1) {
      cout << 0 << endl;
      continue;
    }
    double y = (sqrt(1 + 4 * x) - 1) / 2;
    ll y2 = y;
    ll tot = (y2 * (y2 + 1)) / 2;
    ll ans = 0;
    for (ll i = y2;;i--) {
      ll del = x / 2 - tot;
      if (del > n - 1) break;
      ll l = max(1ll, i + 1 - del), r = min(i, n - del);
      ans += r - l + 1;
      tot -= i;
    }
    if (abs(y - y2) < EPS) {
      ans += (y2 * (y2 - 1)) / 2;
      ans += ((n - y2) * (n - y2 - 1)) / 2;
    }
    cout << ans << endl;
  }
	return 0;
}

