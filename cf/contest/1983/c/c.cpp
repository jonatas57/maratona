#include <bits/stdc++.h>

using namespace std;

typedef long long      ll;
typedef vector<int>    vi;
typedef vector<bool>   vb;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll  INFLL = 0x3f3f3f3f3f3f3f3fll;

#define each(x, s)  for (auto& x : s)
#define loop(x)     for (int i = 0;i < x;i++)
#define vloop(v, x) for (int v = 0;v < x;v++)
#define iter(a)     a.begin(), a.end()
#define riter(a)    a.rbegin(), a.rend()
#define endl        "\n"

ii solve(vector<vector<ll>>& vs, ll p) {
  int x = lower_bound(vs[0].begin() + 1, vs[0].end(), p) - vs[0].begin();
  int y = lower_bound(vs[1].begin() + x + 1, vs[1].end(), p + vs[1][x]) - vs[1].begin();
  if (y == vs[2].size() or vs[2].back() - vs[2][y] < p) return make_pair(-1, -1);
  return make_pair(x, y);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  
  int t;
  cin >> t;
  loop(t) {
    int n;
    cin >> n;
    vector<vector<ll>> vs(3, vector<ll>(n + 1));
    loop(n) cin >> vs[0][i + 1];
    loop(n) cin >> vs[1][i + 1];
    loop(n) cin >> vs[2][i + 1];
    loop(3) vs[i][0] = i;
    each(v, vs) partial_sum(v.begin() + 1, v.end(), v.begin() + 1);
    ll tot = vs[0].back();
    ll p = (tot + 2) / 3;
    int l = -1, r = -1;
    vi a = {0, 1, 2};
    do {
      auto [x, y] = solve(vs, p);
      if (x != -1) {
        l = x;
        r = y;
        break;
      }
    } while (next_permutation(iter(vs)) and next_permutation(iter(a)));
    if (l == -1) cout << -1 << endl;
    else {
      vector<ii> ans = {ii(1, l), ii(l + 1, r), ii(r + 1, n)};
      vi is(3);
      loop(3) is[a[i]] = i;
      each(x, is) cout << ans[x].first << " " << ans[x].second << " ";
      cout << endl;
    }
  }
  return 0;
}

