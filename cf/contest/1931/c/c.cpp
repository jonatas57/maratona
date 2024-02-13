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
    vi a(n);
    loop(n) cin >> a[i];
    map<int, int> m;
    int last = -1;
    loop(n) {
      if (last != -1 and last != a[i]) break;
      m[a[i]]++;
      last = a[i];
    }
    if (m.begin()->second != n) {
      last = -1;
      for (int i = n - 1;i >= 0;i--) {
        if (last != -1 and last != a[i]) break;
        m[a[i]]++;
        last = a[i];
      }
    }
    int ans = n;
    for (auto& [k, v] : m) {
      ans = min(ans, n - v);
    }
    cout << ans << endl;
  }
  return 0;
}

