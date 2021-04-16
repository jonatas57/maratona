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

struct line {
  double a, b, c;
  point vec;
  line(point& p, point& q) : vec(p - q) {
    a = vec.y;
    b = -vec.x;
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

bool isparallel(line& r, line& s) {
  return abs(r.a - s.a) < EPS and abs(r.b - s.b) < EPS;
}

pair<point, bool> intersect(line& r, line& s) {
  if (isparallel(r, s)) return {point(), false};
  double x = (s.b * r.c - r.b * s.c) / (s.a * r.b - r.a * s.b);
  double y = abs(r.b) < EPS ? -(s.a * x + s.c) / s.b : -(r.a * x + r.c) / r.b;
  return {point(x, y), true};
}

double norm(point p) {
  return sqrt(p * p);
}

double dist(point& a, point& b) {
  return norm(a - b);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n, q;
  cin >> n >> q;
  vector<point> ps(n);
  vector<line> ss;
  loop(n) {
    cin >> ps[i];
    if (i) ss.emplace_back(ps[i], ps[i - 1]);
  }
  ss.emplace_back(ps[0], ps[n - 1]);
  int idx, k;
  vector<tuple<int, int, int>> qs;
  loop(q) {
    cin >> idx >> k;
    qs.emplace_back(idx, k, i);
  }
  sort(iter(qs));
  vector<vi> ans(q);
  int base = -1, right = 1, top = 1;
  for (auto& [idx, k, id] : qs) {
    if (idx != base) {
      base = idx;
      top = max(top, base + 1) % n;
      right = max(right, base + 1) % n;
      while ((ss[base].vec ^ ss[top].vec) > EPS) {
        top++;
        if (top >= n) top -= n;
      }
      while ((ss[base].vec * ss[right].vec) > EPS) {
        right++;
        if (right >= n) right -= n;
      }
    }
    int l = right, r = top;
    if (l > r) r += n;
    bool equal = false;
    while (l < r) {
      int mid = avg(l, r);
      int m = mid - (mid >= n ? n : 0);
      auto [p, ok] = intersect(ss[base], ss[m]);
      double d = dist(ps[base], p);
      if (abs(d - k) < EPS) {
        l = r = mid;
        equal = true;
      }
      else if (d + EPS < (double)k) l = mid + 1;
      else r = mid;
    }
    if (equal) ans[id] = {l, l + 1};
    else ans[id] = {l};
  }
  each(v, ans) {
    each(x, v) cout << x % n << " ";
    cout << endl;
  }
  return 0;
}

