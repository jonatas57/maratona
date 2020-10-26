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
  friend istream& operator>>(istream& is, point& p) {
    is >> p.x >> p.y;
    return is;
  }
  double operator^(point p) {
    return x * p.y - y * p.x;
  }
  point operator-(point& p) {
    return point(x - p.x, y - p.y);
  }
  bool operator!=(point& p) {
    return x != p.x or y != p.y;
  }
};

double area(vector<point>& pol) {
  double ans = 0;
  loop((int)pol.size() - 1) {
    ans += pol[i] ^ pol[i + 1];
  }
  return abs(ans / 2);
}

point intersect(point& a, point& b, point& c, point& d) {
  point del = d - c;
  double cr = d ^ c;
  double u = abs(del.y * a.x - del.x * a.y + cr);
  double v = abs(del.y * b.x - del.x * b.y + cr);
  return point((a.x * v + b.x * u) / (u + v), (a.y * v + b.y * u) / (u + v));
}

void cutPolygon(vector<point>& pol, point& a, point& b, int side) {
  vector<point> q;
  int n = pol.size();
  point cut = b - a;
  loop(n) {
    double l1 = cut ^ (pol[i] - a), l2 = 0;
    if (i != n - 1) l2 = cut ^ (pol[i + 1] - a);
    if (l1 * side > -EPS) q.push_back(pol[i]);
    if (l1 * l2 < -EPS) q.push_back(intersect(pol[i], pol[i + 1], a, b));
  }
  if (!q.empty() and q[0] != q.back()) q.push_back(q[0]);
  pol.swap(q);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n, w, h;
  point f;
  for (int t = 1;cin >> n >> w >> h >> f;t++) {
    point a, b;
    vector<point> pol = {{0, 0}, {w, 0}, {w, h}, {0, h}, {0, 0}};
    loop(n) {
      cin >> a >> b;
      double cr = (b - a) ^ (f - a);
      cutPolygon(pol, a, b, cr / abs(cr));
    }
    cout << "Case #" << t << ": " << fixed << setprecision(3) << area(pol) << endl;
  }
  return 0;
}

