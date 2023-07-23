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
    int n, k;
    cin >> n >> k;
    vi a(n);
    loop(n) cin >> a[i];
    vi b(n + 1);
    b[1] = a[0] - 1;
    loop(n - 1) b[i + 2] = a[i + 1] - a[i] - 1;
    partial_sum(iter(b), b.begin());
    ll ans = 1;
    loop(k) {
      int p = lower_bound(iter(b), ans) - b.begin() - 1;
      ans -= b[p];
      ans += p ? a[p - 1] : 0;
    }
    cout << ans << endl;
  }
  return 0;
}

