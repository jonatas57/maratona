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
// #define top(x)             x.front(), x.pop()

#define pb                 push_back
#define eb                 emplace_back

#define div(x, y)          x / y + (x % y != 0)

int main() {
  ios_base::sync_with_stdio(false);

        int n, k;
        cin >> n >> k;
        int r = n * 2, g = 5 * n, b = 8 * n;
        int ans = div(r, k) + div(g, k) + div(b, k);
        cout << ans << endl;
  return 0;
}