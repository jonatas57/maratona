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

int main() {
  ios_base::sync_with_stdio(false);

        int q;
        cin >> q;
        int l, r;
        loop(q) {
                cin >> l >> r;
                int x = l / 2 * (l % 2 ? 1 : -1), y = (r + 1) / 2 * (r % 2 ? -1 : 1);
                cout << y - x << endl;
        }
  return 0;
}