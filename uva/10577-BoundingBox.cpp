#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define INFLL              0x3f3f3f3f3f3f3f3f
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

const double EPS = 1e-7;

struct point {
  double x, y;
  point(double x = 0, double y = 0) : x(x), y(y) {}
  point operator-(const point& p) const {
    return point(x - p.x, y - p.y);
  }
  friend istream& operator>>(istream& is, point& p) {
    is >> p.x >> p.y;
    return is;
  }
  void operator*=(point& p) {
    double a = x * p.x - y * p.y;
    double b = x * p.y + y * p.x;
    x = a;
    y = b;
  }
};

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

point midpoint(point p, point q) {
	return point(avg(p.x, q.x), avg(p.y, q.y));
}

line perpendicular(point& p, point& q) {
  line l(p, q);
  point r = midpoint(p, q);
  return line(-l.b, l.a, l.b * r.x - l.a * r.y);
}

point intersect(line& r, line& s) {
  double x = (r.c * s.b - r.b * s.c) / (r.b * s.a - r.a * s.b);
  return point(x, abs(r.b) < EPS ? -(r.a * x + r.c) / r.b : -(s.a * x + s.c) / s.b);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	for (int t = 1;cin >> n and n;t++) {
		point a, b, c;
    cin >> a >> b >> c;
    line r = perpendicular(a, b), s = perpendicular(b, c);
    point o = intersect(r, s);
    double ang = 2 * acos(-1) / n;
    point p = a - o, w(cos(ang), sin(ang)), hw(cos(ang / 2), sin(ang / 2));
    double minx = p.x, maxx = p.x, miny = p.y, maxy = p.y;
    loop(n - 1) {
      p *= w;
      minx = min(minx, p.x);
      maxx = max(maxx, p.x);
      miny = min(miny, p.y);
      maxy = max(maxy, p.y);
    }
    cout << "Polygon " << t << ": " << fixed << setprecision(3) << (maxx - minx) * (maxy - miny) << endl;
	}
	return 0;
}

