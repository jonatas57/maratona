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

  int n, k;
  cin >> n >> k;
  vi a(n, 0), f(n, INF), l(n, -1);
  int b;
  loop(k) {
    cin >> b;
    a[b - 1]++;
    if (f[b - 1] == INF) f[b - 1] = i;
    l[b - 1] = i;
  }
  ll ans = 0;
  loop(n) {
    if (i > 0) if (f[i] > l[i - 1]) ans++;
    if (!a[i]) ans++;
    if (i < n - 1) if (f[i] > l[i + 1]) ans++;
  }
  cout << ans << endl;
  return 0;
}
