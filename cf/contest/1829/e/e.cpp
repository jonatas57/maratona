#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef vector<bool>       vb;
typedef pair<int, int>     ii;

const int INF = 0x3f3f3f3f;
const ll  INFLL = 0x3f3f3f3f3f3f3f3fll;

#define each(x, s)  for(auto& x : s)
#define loop(x)     for(int i = 0;i < x;i++)
#define vloop(v, x) for(int v = 0;v < x;v++)
#define iter(a)     a.begin(), a.end()
#define riter(a)    a.rbegin(), a.rend()
#define endl        "\n"
#define avg(l, r)   (l + r) / 2

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n, m;
    cin >> n >> m;
    vector<vi> lake(n, vi(m));
    vector<vb> vis(n, vb(m, false));
    loop(n) each(x, lake[i]) cin >> x;
    function<int(int, int)> dfs = [&] (int x, int y) {
      vis[x][y] = true;
      if (!lake[x][y]) return 0;
      int ans = lake[x][y];
      loop(4) {
        int nx = x + (i == 0) - (i == 1);
        int ny = y + (i == 2) - (i == 3);
        if (nx < 0 or nx >= n or ny < 0 or ny >= m or vis[nx][ny]) continue;
        ans += dfs(nx, ny);
      }
      return ans;
    };
    int ans = 0;
    loop(n) vloop(j, m) {
      if (vis[i][j]) continue;
      ans = max(ans, dfs(i, j));
    }
    cout << ans << endl;
  }
  return 0;
}

