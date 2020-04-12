#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long unll;
typedef vector<int>        vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define each(x, s)         for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i += z)
#define loop(x)            for(int i = 0;i < x;i++)
#define vloop(i, x)            for(int i = 0;i < x;i++)

#define pb                 push_back
#define eb                 emplace_back

int main() {
  ios_base::sync_with_stdio(false);

  int t;
  cin >> t;
  int n;
  loop(t) {
    cin >> n;
    int x, ans = 0, m;
    ii mod;
    loop(n) {
      cin >> x;
      if ((m = x % 3) == 0) ans++;
      else (m == 1 ? mod.first : mod.second)++;
    }
    x = min(mod.first, mod.second);
    ans += x;
    mod.first -= x;
    mod.second -= x;
    x = max(mod.first, mod.second);
    ans += x / 3;
    cout << ans << endl;
  }
  return 0;
}
