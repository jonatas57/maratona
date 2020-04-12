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

        int n;
        cin >> n;
        vi hat(n);
        mii hats;
        loop(n) {
                cin >> hat[i];
                hats[hat[i]]++;
        }
        for (int i = 0;i < n;i++) {
                hat[i] = n - hat[i];
        }
        int last = 0;
        mii colors, remaining;
        for (int i = 0;i < n;i++) {
                int x = hat[i];
                if (remaining[colors[x]]) {
                        hat[i] = colors[x];
                        remaining[colors[x]]--;
                }
                else {
                        remaining[++last] = x - 1;
                        colors[x] = last;
                        hat[i] = last;
                }
        }
        bool p = true;
        for (auto& [k, v] : remaining) {
                p &= !v;
                if (!p) break;
        }
        if (p) {
                cout << "Possible\n";
                each(x, hat) cout << x << " ";
                cout << endl;
        }
        else {
                cout << "Impossible\n";
        }
  return 0;
}