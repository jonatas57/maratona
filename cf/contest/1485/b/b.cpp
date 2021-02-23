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

  int n, q, k;
  cin >> n >> q >> k;
  vector<ll> a(n), del(n), acc(n + 1, 0);
  loop(n) cin >> a[i];
  loop(n) {
    del[i] = (i < n - 1 ? a[i + 1] : k + 1) - (i ? a[i - 1] : 0) - 2;
  }
  partial_sum(iter(del), acc.begin() + 1);
  loop(q) {
    int l, r;
    cin >> l >> r;
    ll ans = acc[r] - acc[l - 1];
    if (r < n) ans += k - a[r] + 1;
    if (l > 1) ans += a[l - 2];
    cout << ans << endl;
  }
  return 0;
}

