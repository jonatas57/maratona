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
const double EPS = 1e-8;
const double PI = acos(-1.0);

struct point {
  double x, y;
  point(double x = 0, double y = 0) : x(x), y(y) {}
  point operator+(const point& p) const {
    return point(x + p.x, y + p.y);
  }
  point operator-(const point& p) const {
    return point(x - p.x, y - p.y);
  }
  double operator*(const point& p) const {
    return x * p.x + y * p.y;
  }
  point operator*(const double a) const {
    return point(a * x, a * y);
  }
  double operator^(const point& p) const {
    return x * p.y - y * p.x;
  }
  point operator/(const double a) const {
    return point(x / a, y / a);
  }

  bool operator<(const point& p) const {
    return abs(x - p.x) < EPS ? y + EPS < p.y : x + EPS < p.x;
  }
  bool operator==(const point& p) const {
    return abs(x - p.x) < EPS and abs(y - p.y) < EPS;
  }

  friend istream& operator>>(istream& is, point& p) {
    is >> p.x >> p.y;
    return is;
  }
  friend ostream& operator<<(ostream& os, point& p) {
    os << p.x << " " << p.y;
    return os;
  }
};

double sqnorm(point p) {
  return p * p;
}

double norm(point p) {
  return sqrt(sqnorm(p));
}

double dist(point& a, point& b) {
  return norm(a - b);
}

double angle(point& a, point& o, point& b) {
  point u = a - o, v = b - o;
  return acos(u * v / (norm(u) * norm(v)));
}

struct circle {
  point o;
  double r;
  circle(point o = point(), double r = 0) : o(o), r(r) {}
  friend istream& operator>>(istream& is, circle& c) {
    is >> c.o >> c.r;
    return is;
  }
};

point midpoint(point& a, point& b) {
  return (a + b) / 2;
}

struct line {
  double a, b, c;
  line(point& p, point& q) {
    point del = p - q;
    a = del.y;
    b = -del.x;
    c = -(a * p.x + b * p.y);
  }
  line(double a, double b, double c) : a(a), b(b), c(c) {}
  double eval(point& p) {
    return a * p.x + b * p.y + c;
  }
  bool inside(point& p) {
    return abs(eval(p)) < EPS;
  }
};

vector<point> intersect(circle& c, line& l) {
  double lc = l.c + (l.a * c.o.x + l.b * c.o.y);
  double aux = l.a * l.a + l.b * l.b;
  double d0 = lc * lc / aux;
  if (sqrt(d0) > EPS + c.r) return {};
  point p(-l.a * lc / aux, -l.b * lc / aux);
  if (abs(d0 - c.r * c.r) < EPS) return {p + c.o};
  point v(-l.b, l.a);
  double d = c.r * c.r - d0;
  double m = sqrt(d / aux);
  vector<point> ans;
  v = v * m;
  ans.push_back(p + v + c.o);
  ans.push_back(p - v + c.o);
  return ans;
}

vector<point> intersect(circle& c, circle& d) {
  point del = d.o - c.o;
  line l(2 * del.x, 2 * del.y, sqnorm(c.o) - sqnorm(d.o) - c.r * c.r + d.r * d.r);
  auto ans = intersect(d, l);
  return ans;
}

vector<point> tangentPoint(circle& c, point& p) {
  point mp = midpoint(c.o, p);
  circle d(mp, dist(mp, p));
  return intersect(c, d);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  point st, fin;
  circle b, r;
  cin >> st >> fin >> b >> r;
  vector<vector<point>> ps = {tangentPoint(r, st), tangentPoint(r, fin)};
  double ans = INF;
  loop(2) vloop(j, 2) {
    double ang = angle(ps[0][i], r.o, ps[1][j]);
    ans = min(ans, dist(st, ps[0][i]) + dist(fin, ps[1][j]) + ang * r.r);
  }
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}

