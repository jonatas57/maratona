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
    int n;
    cin >> n;
    vi a(n), b(n);
    map<int, ii> m;
    int cnt = 0, l = -1;
    int x;
    loop(n) {
      cin >> x;
      if (x == l) cnt++;
      else {
        m[l].first = max(cnt, m[l].first);
        cnt = 1;
      }
      l = x;
    }
    m[x].first = max(cnt, m[x].first);
    cnt = 0;
    l = -1;
    loop(n) {
      cin >> x;
      if (x == l) cnt++;
      else {
        m[l].second = max(cnt, m[l].second);
        cnt = 1;
      }
      l = x;
    }
    m[x].second = max(cnt, m[x].second);
    int ans = 0;
    for (auto& [x, p] : m) {
      ans = max(p.first + p.second, ans);
    }
    cout << ans << endl;
  }
  return 0;
}

