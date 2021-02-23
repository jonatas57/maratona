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
    int n, m;
    cin >> n >> m;
    vector<string> mat(n);
    loop(n) cin >> mat[i];
    vector<vector<ll>> cnt(n, vector<ll>(m, 0));
    ll ans = 0;
    for (int i = n - 1;i >= 0;i--) {
      for (int j = 0;j < m;j++) {
        if (mat[i][j] == '*') {
          cnt[i][j]++;
          ll mn = INFLL;
          for (int k = -1;k <= 1;k++) {
            mn = min(mn, i + 1 >= n or j + k < 0 or j + k >= m ? 0ll : cnt[i + 1][j + k]);
          }
          cnt[i][j] += mn;
          ans += cnt[i][j];
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}

