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

struct point {
  double x, y;
  point(double x = 0, double y = 0) : x(x), y(y) {}
  point operator-(const point& p) const {
    return point(x - p.x, y - p.y);
  }
  void operator-=(const point& p) {
    x -= p.x;
    y -= p.y;
  }
  void operator+=(const point& p) {
    x += p.x;
    y += p.y;
  }
  double operator*(const point& p) const {
    return x * p.x + y * p.y;
  }
  friend istream& operator>>(istream& is, point& p) {
    is >> p.x >> p.y;
    return is;
  }
  friend ostream& operator<<(ostream& os, point& p) {
    os << fixed << setprecision(7) << p.x << " " << fixed << setprecision(7) << p.y;
    return os;
  }
};

double norm(point p) {
  return sqrt(p * p);
}

double dist(point& a, point& b) {
  return norm(a - b);
}

double angle(point a, point& o, point& b) {
  point u = a - o, v = b - o;
  return acos(u * v / (norm(u) * norm(v))) * (v.y < 0 ? -1 : 1);
}

void rot(point& p, double ang) {
  double c = cos(ang), s = sin(ang);
  double x = p.x * c - s * p.y, y = p.x * s + c * p.y;
  p.x = x;
  p.y = y;
}

point solve(point& A, point& B, point& P, point& Q) {
  point a = A - P, b = B - P, p, q = Q - P;
  double ang = angle(point(1, 0), p, q);
  rot(a, -ang), rot(b, -ang), rot(q, -ang);
  point aux(a.x, 0);
  a -= aux, b -= aux, p -= aux, q -= aux;

  double delx = b.x / (a.y + b.y) * a.y;
  point ans(clamp(delx, p.x, q.x));
  
  ans += aux;
  rot(ans, ang);
  ans += P;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  freopen("flags.in", "r", stdin);

  int t;
  cin >> t;
  loop(t) {
    int n;
    cin >> n;
    vector<point> ps(n);
    loop(n) cin >> ps[i];
    ps.push_back(ps[0]);
    int q;
    cin >> q;
    cout << "Case " << i + 1 << ":" << endl;
    loop(q) {
      point a, b;
      cin >> a >> b;
      double ans = INFLL;
      point q;
      loop(n) {
        point p = solve(a, b, ps[i], ps[i + 1]);
        double aux = dist(a, p) + dist(p, b);
        if (aux < ans) {
          ans = aux;
          q = p;
        }
      }
      cout << fixed << setprecision(7) << ans << " " << q << endl;
    }
  }
  return 0;
}

