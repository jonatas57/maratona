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
    vi a(n + 2, 0);
    loop(n) cin >> a[i + 1];
    a[n + 1] = 2 * n + 1;
    int ans = n + 1;
    int r = 0;
    for (int i = 1;i <= n;i++) {
      r += a[i] - a[i - 1] - 1;
      if (r == 0) ans--;
      else r--;
    }
    int l = 0;
    for (int i = n;i > 0;i--) {
      l += a[i + 1] - a[i] - 1;
      if (l == 0) ans--;
      else l--;
    }
    cout << ans << endl;
  }
  return 0;
}

