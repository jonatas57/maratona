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
#define vloop(i, x)        for(int i = 0;i < x;i++)

#define pb                 push_back
#define eb                 emplace_back

int main() {
  ios_base::sync_with_stdio(false);

  int k;
  cin >> k;
  int n, m;
  string cs = "aeiou";
  bool p = false;
  for (n = 5;n * n <= k;n++) {
    if (k % n == 0 && k / n >= 5) {
      m = k / n;
      p = true;
      break;
    }
  }
  string ans = "";
  if (p) {
    loop(n) {
      vloop(j, m) {
        ans += cs[(i + j) % 5];
      }
    }
    cout << ans << endl;
  }
  else cout << -1 << endl;
  return 0;
}
