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
const double EPS = 1e-6;

struct point {
  int x, y;
  point(int x = 0, int y = 0) : x(x), y(y) {}
  point operator-(point& p) {
    return point(x - p.x, y - p.y);
  }
};

istream& operator>>(istream& is, point& p) {
  is >> p.x >> p.y;
  return is;
}

struct line {
  point p, q;
  int a, b, c;
  line(point x, point y) : p(x), q(y) {
    point del = p - q;
    a = -del.y;
    b = del.x;
    c = -(a * p.x + b * p.y);
  }
  bool inside(double x, double y) {
    if (abs(a * x + b * y + c) > EPS) return false;
    return min(p.x, q.x) <= x and x <= max(p.x, q.x) and min(p.y, q.y) <= y and y <= max(p.y, q.y);
  }
  double eval(point& p) {
    return a * p.x + b * p.y + c;
  }
};

double min(double a, double b) {
  return a + EPS < b ? a : b;
}

double dist(point& p, point& q) {
  point del = p - q;
  return sqrt(del.x * del.x + del.y * del.y);
}

double dist(line& l, point& p) {
  double ans = min(dist(l.p, p), dist(l.q, p));
  ll div = l.a * l.a + l.b * l.b;
  double aux = l.b * p.x - l.a * p.y;
  double x = (aux * l.b - l.a * l.c) / div;
  double y = (-aux * l.a - l.b * l.c) / div;
  if (l.inside(x, y)) ans = min(ans, abs(l.eval(p)) / sqrt(div));
  return ans;
}

double arr(double a) {
  int b = a * 10000;
  if (b % 10 >= 5) b++;
  return b / 10000.0;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  string t;
  while (cin >> t and t[0] != '*') {
    int n = stoi(t);
    point o;
    cin >> o;
    vector<point> pol(n);
    loop(n) cin >> pol[i];
    pol.push_back(pol[0]);
    double ans = INF;
    loop(n) {
      line l(pol[i], pol[i + 1]);
      ans = min(ans, dist(l, o));
    }
    cout << fixed << setprecision(3) << arr(ans) << endl;
  }
  return 0;
}

