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
const double EPS = 1e-5;
const double PI = acos(-1);

struct point {
  ll x, y;
  double ang;
  point(ll x = 0, ll y = 0) : x(x), y(y) {}
  point operator-(point& p) {
    return point(x - p.x, y - p.y);
  }
  friend istream& operator>>(istream& is, point& p) {
    is >> p.x >> p.y;
    return is;
  }
  bool operator==(point& p) {
    return x == p.x and y == p.y;
  }
  void calcang(point& pivo) {
    if (operator==(pivo)) { ang = -INF; return; }
    point p = operator-(pivo);
    double alfa = acos(p.x / p.norm());
    ang = p.y > 0 ? alfa : -alfa;
  }
  bool operator<(point& p) {
    return ang < p.ang;
  }
  double norm() {
    return sqrt(x * x + y * y);
  }
};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n;
  cin >> n;
  vector<point> ps, ps2;
  ll tot = 0;
  unordered_map<int, unordered_map<int, ll>> vals;
  auto val = [&vals](point& p) {
    return vals[p.x][p.y];
  };
  loop(n) {
    point p;
    ll g;
    cin >> p >> g;
    ps.push_back(p);
    ps2.push_back(p);
    vals[p.x][p.y] = g;
    tot += g;
  }
  ll ans = INFLL;
  for (auto& pivo : ps2) {
    tot -= val(pivo);
    loop(n) ps[i].calcang(pivo);
    sort(iter(ps));
    int i = 1, j = 2;
    tot -= val(ps[i]);
    ll sum = 0;
    double extra = 0;
    for (;i < n;) {
      if (abs(ps[j].ang - ps[i].ang + EPS + extra) < PI) {
        sum += val(ps[j]);
        j++;
        if (j == n) {
          extra += 2 * PI;
          j = 1;
        }
      }
      else {
        ans = min(ans, abs(sum - tot + sum));
        tot += val(ps[i]);
        i++;
        sum -= val(ps[i]);
        tot -= val(ps[i]);
      }
    }
    tot += val(ps[i]);
    tot += val(pivo);
  }
  cout << ans << endl;
  return 0;
}

