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

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n, m;
  cin >> n >> m;
  vector<ii> rs, ls;
  int a, b;
  loop(n) cin >> a >> b, rs.emplace_back(a, b);
  loop(m) {
    cin >> a >> b;
    vloop(j, n) {
      ls.emplace_back(a - rs[j].first, b - rs[j].second);
    }
  }
  sort(riter(ls));
  int ans = INF, miny = 0;
  for (auto& [x, y] : ls) {
    if (x < 0) break;
    ans = min(ans, x + 1 + miny);
    miny = max(miny, y + 1);
  }
  ans = min(ans, miny);
  cout << ans << endl;
  return 0;
}

