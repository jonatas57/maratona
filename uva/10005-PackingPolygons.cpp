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
const double EPS = 1e-9;

struct point {
  double x, y;
  point(double x = 0, double y = 0) : x(x), y(y) {}
  point operator-(point& p) {
    return point(x - p.x, y - p.y);
  }
  ll operator*(point& p) {
    return x * p.x + y * p.y;
  }
  bool operator<(const point& p) const {
    return abs(x - p.x) < EPS ? y + EPS < p.y : x + EPS < p.x;
  }
};

istream& operator>>(istream& is, point& p) {
  is >> p.x >> p.y;
  return is;
}

double dist(point& p, point& q) {
  point del = p - q;
  return sqrt(del.x * del.x + del.y * del.y);
}

point midpoint(point& p, point& q) {
  return point((p.x + q.x) / 2, (p.y + q.y) / 2);
}

ll cross(point& p, point& q) {
  return p.x * q.y - p.y * q.x;
}

struct circle {
  point o;
  double r;
  circle(point& a, point& b) : o(midpoint(a, b)), r(dist(a, b) / 2) {}
  circle(point& a, point& b, point& c) {
    point del1 = b - a, del2 = c - a;
    ll x = del1 * del1, y = del2 * del2, z = 2 * cross(del1, del2);
    o = point(a.x + (del2.y * x - del1.y * y) / z, a.y + (del1.x * y - del2.x * x) / z);
    r = dist(o, a);
  }
  circle(point p, double r) : o(p), r(r) {}
  bool inside(point& p) {
    return dist(p, o) < EPS + r;
  }
  bool operator<(const circle& c) const {
    return abs(r - c.r) < EPS ? o < c.o : r + EPS < c.r;
  }
};

circle welzl(vector<point>& ps, int n, vector<point> rs, int r) {
  if (n == -1 or r == 3) {
    if (r == 0) return circle({INF, INF}, 0);
    if (r == 1) return circle(rs[0], 0);
    if (r == 2) return circle(rs[0], rs[1]);
    vector<pair<circle, point>> x = {{circle(rs[0], rs[1]), rs[2]}, {circle(rs[0], rs[2]), rs[1]}, {circle(rs[1], rs[2]), rs[0]}};
    sort(iter(x));
    each(p, x) {
      if (p.first.inside(p.second)) return p.first;
    }
    return circle(rs[0], rs[1], rs[2]);
  }
  circle c = welzl(ps, n - 1, rs, r);
  if (c.inside(ps[n])) return c;
  rs.push_back(ps[n]);
  return welzl(ps, n - 1, rs, r + 1);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n;
  while (cin >> n and n) {
    vector<point> ps(n), rs;
    loop(n) cin >> ps[i];
    double r;
    cin >> r;
    circle c = welzl(ps, n - 1, rs, 0);
    cout << (c.r < r + EPS ? "The polygon can be packed in the circle." : "There is no way of packing that polygon.") << endl;
  }
  return 0;
}

