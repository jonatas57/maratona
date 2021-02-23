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
    int n;
    cin >> n;
    vector<ll> ts(n), xs(n);
    loop(n) cin >> ts[i] >> xs[i];
    ts.push_back(INFLL);
    ll ans = 0, dest = 0, tf = 0, at = 0;
    loop(n) {
      if (ts[i] >= tf) dest = xs[i], tf = ts[i] + abs(at - dest);
      ll r = (tf <= ts[i + 1] ? dest : at + (ts[i + 1] - ts[i]) * (dest < at ? -1 : 1));
      ll l = at;
      ll next = r;
      if (l > r) swap(l, r);
      if (l <= xs[i] and xs[i] <= r) ans++;
      at = next;
    }
    cout << ans << endl;
  }
  return 0;
}

