#include <bits/stdc++.h>

using namespace std;

typedef long long      ll;
typedef vector<int>    vi;
typedef vector<bool>   vb;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll  INFLL = 0x3f3f3f3f3f3f3f3fll;

#define each(x, s)  for (auto& x : s)
#define loop(x)     for (int i = 0;i < x;i++)
#define vloop(v, x) for (int v = 0;v < x;v++)
#define iter(a)     a.begin(), a.end()
#define riter(a)    a.rbegin(), a.rend()
#define endl        "\n"

ll xorall(ll x) {
  if (x & 1) return (x + 1) % 4 != 0;
  return x % 4 == 0 ? x : x + 1;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    ll l, r, b, k;
    cin >> l >> r >> b >> k;
    l--;
    ll ans = xorall(r) xor xorall(l);
    ll l2 = (l - k) >> b;
    ll r2 = (r - k) >> b;
    ans ^= (xorall(r2) xor xorall(l2)) << b;
    if ((r2 - l2) & 1) ans ^= k;
    cout << ans << endl;
  }
  return 0;
}

