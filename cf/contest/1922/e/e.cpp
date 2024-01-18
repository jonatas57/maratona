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
    ll x;
    cin >> x;
    int msb = 0;
    for (ll m = 1;m <= x;msb++, m <<= 1);
    msb--;
    int p = __builtin_popcountll(x) - 1;
    int n = msb + p;
    vi ans(n);
    for (int i = 0, j = 0;i < msb;i++) {
      if (x & (1ll << i)) {
        ans[n - 1 - i - j] = j - p;
        j++;
      }
    }
    for (int i = 0, j = 0;i < n;i++) {
      if (!ans[i]) ans[i] = j++;
    }
    cout << ans.size() << endl;
    each(x, ans) cout << x << " ";
    cout << endl;
  }
  return 0;
}

