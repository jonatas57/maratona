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

  int h, w;
  cin >> h >> w;
  vector<string> ss(h);
  vector<vector<vector<ll>>> acc(h + 1, vector<vector<ll>>(w + 1, vector<ll>(4, 0)));
  loop(h) cin >> ss[i];
  acc[1][1] = {1, 1, 1, 1};
  for (int i = 1;i <= h;i++) {
    for (int j = 1;j <= w;j++) {
      if (i == j and j == 1) continue;
      if (ss[i - 1][j - 1] == '#') acc[i][j] = {0, 0, 0, 0};
      else {
        acc[i][j][0] = acc[i][j - 1][1] + acc[i - 1][j][2] + acc[i - 1][j - 1][3];
        acc[i][j][1] = acc[i][j - 1][1] + acc[i][j][0];
        acc[i][j][2] = acc[i - 1][j][2] + acc[i][j][0];
        acc[i][j][3] = acc[i - 1][j - 1][3] + acc[i][j][0];
        vloop(k, 4) acc[i][j][k] %= mod;
      }
    }
  }
  cout << acc[h][w][0] << endl;
  return 0;
}

