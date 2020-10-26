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
  point operator*(const ll a) const {
    return point(a * x, a * y);
  }
  double operator^(const point& p) const {
    return x * p.y - y * p.x;
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

point midpoint(point p, point q) {
	return point(avg(p.x, q.x), avg(p.y, q.y));
}

double dist(const point& p, const point& q) {
  point del = p - q;
  return sqrt(del * del);
}

struct circle {
  point o;
  double r;
  circle(point o = point(), double r = 0) : o(o), r(r) {}
  circle(point a, point b) : o(midpoint(a, b)), r(dist(a, b) / 2) {}
  circle(point& a, point& b, point& c) {
    point del1 = b - a, del2 = c - a;
    double x = del1 * del1, y = del2 * del2, z = 2 * (del1 ^ del2);
    o = point(a.x + (del2.y * x - del1.y * y) / z, a.y + (del1.x * y - del2.x * x) / z);
    r = dist(o, a);
  }
  bool inside(point& p) {
    return dist(p, o) < EPS + r;
  }
  bool operator==(const circle& c) const {
    return o == c.o and abs(r - c.r) < EPS;
  }
  bool operator<(const circle& c) const {
    return abs(r - c.r) > EPS ? r + EPS < c.r : o + EPS < c.o;
  }
};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int m;
  cin >> m;
  vector<double> hs(m);
  loop(m) cin >> hs[i];
  int n;
  cin >> n;
  loop(n) {
    double a, b, c;
    cin >> a >> b >> c;
    double cs = (b * b + c * c - a * a) / (2 * b * c);
    point p, q(c), r(b * cs, b * sqrt(1 - cs * cs));
    circle circun(p, q, r);
    double diam = circun.r * 2;
    vector<pair<circle, point>> x = {{circle(p, q), r}, {circle(p, r), q}, {circle(q, r), p}};
    each(p, x) {
      if (p.first.inside(p.second)) diam = min(diam, 2 * p.first.r);
    }
    vi ans;
    loop(m) if (diam < EPS + hs[i]) ans.push_back(i + 1);
    cout << "Peg " << (char)('A' + i) << " will ";
    if (ans.empty()) cout << "not fit into any holes" << endl;
    else {
      cout << "fit into hole(s):";
      each(x, ans) cout << " " << x;
      cout << endl;
    }
  }
  return 0;
}

