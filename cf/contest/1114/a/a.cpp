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

#define pb                 push_back
#define eb                 emplace_back

int main() {
  ios_base::sync_with_stdio(false);

  int x, y, z, a, b, c;
  cin >> x >> y >> z >> a >> b >> c;
  bool A = false, D = false, M = false;
  if (x <= a) {
    a -= x;
    A = true;
    b += a;
    if (y <= b) {
      b -= y;
      D = true;
      c += b;
      if (z <= c) {
        c -= z;
        M = true;
      }
    }
  }
  cout << (A && D && M ? "YES" : "NO") << endl;
  return 0;
}
