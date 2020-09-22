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

struct point {
  ll x, y;
  point(ll x = 0, ll y = 0) : x(x), y(y) {}
  ll operator*(point p) {
    return x * p.y - y * p.x;
  }
};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n;
  ll x, y;
  cin >> n;
  vector<point> ps;
  loop(n) {
    cin >> x >> y;
    ps.emplace_back(x, y);
  }
  ps.push_back(ps[0]);
  ps.push_back(ps[1]);
  ll ans = INFLL;
  vector<ll> acc(n + 3, 0);
  for (int i = 1;i < n + 2;i++) {
    acc[i] = acc[i - 1] + ps[i - 1] * ps[i];
    if (i >= 2) {
      ll area = acc[i] - acc[i - 2];
      area += ps[i] * ps[i - 2];
      ans = min(ans, abs(area));
    }
  }
  cout << ans << endl;
  return 0;
}

