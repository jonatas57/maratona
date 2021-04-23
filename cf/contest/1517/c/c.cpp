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

  int n;
  cin >> n;
  vi a(n);
  loop(n) cin >> a[i];
  vector<vi> ans;
  loop(n) ans.emplace_back(i + 1, 0);
  bool one = false;
  loop(n) {
    ans[i][i] = a[i];
    int x = i, y = i;
    vloop(j, a[i] - 1) {
      if (one) {
        if (x > y and !ans[x - 1][y]) x--;
        else if (!y or ans[x][y - 1]) x++;
        else y--;
      }
      else {
        if (y and !ans[x][y - 1]) y--;
        else if (x == n - 1 or ans[x + 1][y]) y++;
        else x++;
      }
      ans[x][y] = a[i];
    }
    if (a[i] == 1) one = true;
  }
  each(v, ans) {
    each(x, v) cout << x << " ";
    cout << endl;
  }
  return 0;
}

