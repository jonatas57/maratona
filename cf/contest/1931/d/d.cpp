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
    int n, x, y;
    cin >> n >> x >> y;
    map<int, map<int, ll>> m;
    int a;
    loop(n) {
      cin >> a;
      m[a % y][a % x]++;
    }
    ll ans = 0;
    for (auto& [r, m2] : m) {
      for (auto& [r2, cnt] : m2) {
        int c = r2 ? x - r2 : 0;
        if (r2 == c) {
          ans += cnt * (cnt - 1) / 2;
        }
        else if (c < r2) break;
        else if (m2.count(c)) {
          ans += cnt * m2[c];
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}

