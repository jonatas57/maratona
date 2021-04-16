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

vector<vector<vi>> dp, a;

int solve(int f, int x, int y) {
  if (f <= 0 or x > 10 or y > 10) return 0;
  if (dp[f][x][y] == -1) {
    dp[f][x][y] = max({solve(f - 1, x, y), solve(f, x + 1, y), solve(f, x, y + 1)}) + a[f][x][y];
  }
  return dp[f][x][y];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  freopen("commandos.in", "r", stdin);

  int t;
  cin >> t;
  loop(t) {
    int n;
    cin >> n;
    dp.assign(11, vector<vi>(11, vi(11, -1)));
    a.assign(11, vector<vi>(11, vi(11, 0)));
    int f, x, y, h;
    loop(n) {
      cin >> f >> x >> y >> h;
      a[f][x][y] += h;
    }
    cout << solve(10, 1, 1) << endl;
  }
  return 0;
}

