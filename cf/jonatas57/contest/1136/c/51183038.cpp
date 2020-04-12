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
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

  int n, m;
  cin >> n >> m;
  vector<mii> a(n + m - 1), b(n + m - 1);
  int x;
  loop(n) vloop(j, m) cin >> x, a[i + j][x]++;
  loop(n) vloop(j, m) cin >> x, b[i + j][x]++;
  bool ans = true;
  loop(n + m - 1) {
    each(p, a[i]) {
      ans &= (b[i][p.first] == p.second);
    }
  }
  cout << (ans ? "YES\n" : "NO\n");
  return 0;
}
