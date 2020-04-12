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

  int n, h, m;
  cin >> n >> h >> m;
  vi a(n, h);
  int l, r, x;
  loop(m) {
    cin >> l >> r >> x;
    rep(l - 1, r, 1) {
      a[i] = min(a[i], x);
    }
  }
  int ans = 0;
  each(p, a) {
    ans += p * p;
  }
  cout << ans << endl;
  return 0;
}
