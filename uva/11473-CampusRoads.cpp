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
  void operator+=(point& p) {
    x += p.x;
    y += p.y;
  }
  point operator-(point& p) {
    return point(x - p.x, y - p.y);
  }
  point operator*(double a) {
    return point(a * x, a * y);
  }
  double operator*(point& p) {
    return x * p.x + y * p.y;
  }
  point operator/(double a) {
    return point(x / a, y / a);
  }
};

double dist(point& p, point& q) {
  point del = p - q;
  return sqrt(del * del);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n, k;
    cin >> n >> k;
    double len = 0;
    vector<point> ps(n);
    loop(n) {
      cin >> ps[i].x >> ps[i].y;
      if (i) len += dist(ps[i], ps[i - 1]);
    }
    k--;
    double del = len / k, step = del;
    vector<point> ans(1, ps[0]);
    point last = ps[0];
    for (int i = 1, j = 1;i < k;) {
      double d = dist(ps[j], last);
      if (d + EPS < step) {
        step -= d;
        last = ps[j];
        j++;
      }
      else {
        point v = (ps[j] - last) / dist(ps[j], last) * step;
        last += v;
        ans.push_back(last);
        step = del;
        i++;
      }
    }
    ans.push_back(ps.back());
    cout << "Road #" << i + 1 << ":" << endl;
    each(p, ans) cout << fixed << setprecision(2) << p.x << " " << fixed << setprecision(2) << p.y << endl;
    cout << endl;
  }
  return 0;
}

