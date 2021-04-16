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

typedef tuple<ll, int, int> tup;

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#ifndef MEUPC
  freopen("bishops.in", "r", stdin);
#endif

  int t;
  cin >> t;
  loop(t) {
    ll n, m, c;
    cin >> n >> m >> c;
    vector<vector<vector<tup>>> diag(2, vector<vector<tup>>(2 * n + 1));
    ll x, y, p;
    loop(m) {
      cin >> x >> y >> p;
      x--, y--;
      p *= p;
      ll a = min(x, y), b = min(x, n - 1 - y);
      diag[0][n - 1 - x + y].emplace_back(a - p + 1, 0, i);
      diag[0][n - 1 - x + y].emplace_back(a + p + c - 1, 1, i);
      diag[1][x + y].emplace_back(b - p + 1, 0, i);
      diag[1][x + y].emplace_back(b + p + c - 1, 1, i);
    }
    int ans = 0;
    vector<vi> a(2, vi(m, 0));
    loop(2) {
      vloop(j, 2 * n + 1) {
        sort(iter(diag[i][j]));
        int last = -1; 
        for (auto& [x, rem, id] : diag[i][j]) {
          if (rem) {
            if (last == -1 or a[i][last] < a[i][id]) last = id;
          }
          else {
            if (last == -1) a[i][id] = 1;
            else a[i][id] = a[i][last] + 1;
            ans = max(a[i][id], ans);
          }
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}

