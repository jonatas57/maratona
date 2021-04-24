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
    vector<vi> a(n, vi(m));
    loop(n) vloop(j, m) cin >> a[i][j];
    vector<vi> ul(n, vi(m, 0)), ur = ul, dl = ul, dr = ul;
    int ans = INF;

    for (int i = 1;i + 1 < n;i++) for (int j = 1;j + 1 < m;j++) ul[i][j] = max({ul[i - 1][j], ul[i][j - 1], a[i - 1][j - 1]});
    for (int i = 1;i + 1 < n;i++) for (int j = m - 2;j > 0;j--) ur[i][j] = max({ur[i - 1][j], ur[i][j + 1], a[i - 1][j + 1]});
    for (int i = n - 2;i > 0;i--) for (int j = 1;j + 1 < m;j++) dl[i][j] = max({dl[i + 1][j], dl[i][j - 1], a[i + 1][j - 1]});
    for (int i = n - 2;i > 0;i--) for (int j = m - 2;j > 0;j--) dr[i][j] = max({dr[i + 1][j], dr[i][j + 1], a[i + 1][j + 1]});

    for (int i = 1;i + 1 < n;i++) for (int j = 1;j + 1 < m;j++) {
      int x = INF, y = 0;
      x = min({ul[i][j], ur[i][j], dl[i][j], dr[i][j]});
      y = max({ul[i][j], ur[i][j], dl[i][j], dr[i][j]});
      ans = min(ans, y - x);
    }
    cout << ans << endl;
  }
  return 0;
}

