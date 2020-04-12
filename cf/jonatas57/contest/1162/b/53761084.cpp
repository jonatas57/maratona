#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long unll;
typedef vector<int>        vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define each(x, s)         for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i += z)
#define loop(x)            for(int i = 0;i < x;i++)
#define vloop(i, x)            for(int i = 0;i < x;i++)

#define pb                 push_back
#define eb                 emplace_back

int main() {
  ios_base::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  vector<vi> a(n, vi(m)), b(n, vi(m));
  loop(n) vloop(j, m) {
    cin >> a[i][j];
  }
  loop(n) vloop(j, m) {
    cin >> b[i][j];
  }
  bool p = true;
  for (int i = 0;i < n && p;i++) {
    for (int j = 0;j < m && p;j++) {
      int x = a[i][j], y = b[i][j];
      if (x > y) swap(x, y);
      if ((i == 0 || (a[i - 1][j] < x && b[i - 1][j] < y)) && (j == 0 || (a[i][j - 1] < x && b[i][j - 1] < y))) a[i][j] = x, b[i][j] = y;
      else if ((i == 0 || (a[i - 1][j] < y && b[i - 1][j] < x)) && (j == 0 || (a[i][j - 1] < y && b[i][j - 1] < x))) a[i][j] = y, b[i][j] = x;
      else p = false;
    }
  }
  cout << (p ? "Possible\n" : "Impossible\n");
  return 0;
}
/*

1 3
2 4
5 10

3 1
3 6
4 8

*/
