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
#define avg(l, r)          (l + r) >> 1
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

const ll mod = 1000000007;
const double EPS = 1e-7;
const double PI = acos(-1);

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n, m;
  cin >> n >> m;
  vector<ii> a;
  int ans = 0;
  loop(m) {
    int x, y;
    cin >> x >> y;
    a.emplace_back(x, y);
    ans = max(ans, y);
  }
  ans = max({ans, a.front().second + a.front().first - 1, a.back().second + n - a.back().first});
  bool pos = true;
  loop(m - 1) {
    if (abs(a[i + 1].first - a[i].first) < abs(a[i + 1].second - a[i].second)) pos = false;
    if (!pos) break;
    int del = (a[i + 1].first - a[i].first - abs(a[i + 1].second - a[i].second)) >> 1;
    ans = max(ans, max(a[i].second, a[i + 1].second) + del);
  }
  if (pos) cout << ans << endl;
  else cout << "IMPOSSIBLE" << endl;
  return 0;
}

