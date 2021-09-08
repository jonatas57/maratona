#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>        vi;
typedef vector<bool>       vb;
typedef map<int, ll>       mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define INFLL              0x3f3f3f3f3f3f3f3f
#define each(x, s)         for(auto& x : s)
#define loop(x)            for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          (l + r) >> 1
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

const ll mod = 1000000007;
const double EPS = 1e-7;
const double PI = acos(-1);

ll solve(mii& hor, map<int, mii>& hcnt) {
  ll ans = 0;
  for (auto& [x, qtd] : hor) {
    ans += qtd * (qtd - 1);
    for (auto& [y, qtd2] : hcnt[x]) {
      ans -= qtd2 * (qtd2 - 1);
    }
  }
  return ans >> 1;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n, m, k;
    cin >> n >> m >> k;
    vi xs(n), ys(m);
    loop(n) cin >> xs[i];
    loop(m) cin >> ys[i];
    ll ans = 0;
    mii hor, ver;
    map<int, mii> hcnt, vcnt;
    loop(k) {
      int x, y;
      cin >> x >> y;
      int x1 = *lower_bound(iter(xs), x);
      int y1 = *lower_bound(iter(ys), y);
      if (x1 != x) {
        hor[x1]++;
        hcnt[x1][y]++;
      }
      if (y1 != y) {
        ver[y1]++;
        vcnt[y1][x]++;
      }
    }
    ans += solve(hor, hcnt);
    ans += solve(ver, vcnt);
    cout << ans << endl;
  }
  return 0;
}

