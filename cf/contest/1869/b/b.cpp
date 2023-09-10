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

ll manhattan(pair<ll, ll> a, pair<ll, ll> b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n, k, a, b;
    cin >> n >> k >> a >> b;
    a--, b--;
    vector<pair<ll, ll>> cs;
    loop(n) {
      ll x, y;
      cin >> x >> y;
      cs.emplace_back(x, y);
    }
    ll ans = manhattan(cs[a], cs[b]);
    ll toa = INFLL, tob = INFLL;
    loop(k) {
      toa = min(toa, manhattan(cs[i], cs[a]));
      tob = min(tob, manhattan(cs[i], cs[b]));
    }
    ans = min(ans, toa + tob);
    cout << ans << endl;
  }
  return 0;
}

