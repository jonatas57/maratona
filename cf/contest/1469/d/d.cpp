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
    vector<ii> ans;
    if (n > 8) {
      for (int i = 3;i < n;i++) {
        if (i == 8) continue;
        ans.emplace_back(i, n);
      }
      for (int x = n;x > 1;x = (x + 7) / 8) ans.emplace_back(n, 8);
      loop(3) ans.emplace_back(8, 2);
    }
    else {
      for (int i = 3;i < n;i++) ans.emplace_back(i, n);
      for (int x = n;x > 1;x = (x + 1) / 2) ans.emplace_back(n, 2);
    }
    cout << ans.size() << endl;
    for (auto& [x, y] : ans) cout << x << " " << y << endl;
  }
  return 0;
}

