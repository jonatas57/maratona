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
#define double             long double

const ll mod = 1000000007;
const double EPS = 1e-7;
const double PI = acos(-1);

struct point {
  double x, y;
  point(double x = 0, double y = 0) : x(x), y(y) {}
  point operator+(const point& p) const {
    return point(x + p.x, y + p.y);
  }
  point operator-(const point& p) const {
    return point(x - p.x, y - p.y);
  }
  point operator*(const double a) const {
    return point(a * x, a * y);
  }
  double operator*(const point& p) const {
    return x * p.x + y * p.y;
  }

  friend istream& operator>>(istream& is, point& p) {
    is >> p.x >> p.y;
    return is;
  }
};

double norm(point p) {
  return sqrt(p * p);
}

double dist(point& a, point& b) {
  return norm(a - b);
}

point ref(point& h, ll x) {
  return point(x - h.x + x, h.y);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int a, b, c, x;
    cin >> a >> b >> c >> x;
    point h(0, 0), gm(-b, -a), v = h - gm;
    point e = gm + v * (x / 100.0);
    point h2 = ref(h, c);
    double ans = dist(h2, gm) + dist(gm, e) + dist(e, h2);
    cout << fixed << setprecision(10) << ans << endl;
  }
  return 0;
}

