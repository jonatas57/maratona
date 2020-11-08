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

  int h, w, n, m;
  cin >> h >> w >> n >> m;
  vector<vb> grid(h, vb(w, true));
  int ans = h * w, x, y;
  vector<vi> lvs(w, vi(1, -2)), bvs(w, vi(1, -1)), lhs(h, vi(1, -2)), bhs(h, vi(1, -1));
  loop(n) {
    cin >> x >> y;
    x--, y--;
    grid[x][y] = false;
    lhs[x].push_back(y);
    lvs[y].push_back(x);
  }
  loop(m) {
    cin >> x >> y;
    x--, y--;
    grid[x][y] = false;
    bhs[x].push_back(y);
    bvs[y].push_back(x);
    ans--;
  }
  loop(h) {
    lhs[i].push_back(INF + 1);
    bhs[i].push_back(INF);
    sort(iter(lhs[i]));
    sort(iter(bhs[i]));
  }
  loop(w) {
    lvs[i].push_back(INF + 1);
    bvs[i].push_back(INF);
    sort(iter(lvs[i]));
    sort(iter(bvs[i]));
  }
  vi vls(w, 0), vbs(w, 0);
  loop(h) {
    int hl = 0, hb = 0;
    vloop(j, w) {
      if (lhs[i][hl + 1] == j) {
        hl++;
        vls[j]++;
      }
      else if (bhs[i][hb + 1] == j) {
        hb++;
        vbs[j]++;
      }
      if (!grid[i][j]) continue;
      if (lhs[i][hl] < bhs[i][hb] and lhs[i][hl + 1] > bhs[i][hb + 1] and lvs[j][vls[j]] < bvs[j][vbs[j]] and lvs[j][vls[j] + 1] > bvs[j][vbs[j] + 1]) {
        ans -= grid[i][j];
        grid[i][j] = false;
      }
    }
  }
  cout << ans << endl;
  return 0;
}

