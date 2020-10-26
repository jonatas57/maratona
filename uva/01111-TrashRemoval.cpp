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
  ll x, y;
  point(ll x = 0, ll y = 0) : x(x), y(y) {}
  ll operator*(point& p) {
    return x * p.x + y * p.y;
  }
  point operator-(point& p) {
    return point(x - p.x, y - p.y);
  }
  bool operator<(const point& p) const {
    return x == p.x ? y < p.y : x < p.x;
  }
};

ll cross(point p, point q) {
  return p.x * q.y - p.y * q.x;
}

double norm(point& p) {
  return sqrt(p * p);
}

double dist(point& p, point& q) {
  point del = p - q;
  return norm(del);
}

double dist(point& p, point& q, point& r) {
  point del = q - r;
  return abs(del.y * p.x - del.x * p.y - cross(r, q)) / norm(del);
}

vector<point> convexHull(vector<point>& ps, int n) {
  sort(iter(ps));
  point pivo = ps[0];
  sort(ps.begin() + 1, ps.end(), [&pivo](point& p, point& q) {
    point del1 = p - pivo, del2 = q - pivo;
    double a = del1.y * norm(del2);
    double b = del2.y * norm(del1);
    return abs(a - b) < EPS ? dist(pivo, p) > EPS + dist(pivo, q) : a < b;
  });
  ps.push_back(pivo);
  vector<point> ch = {ps[0], ps[1]};
  for (int i = 2, j = 1;i <= n;) {
    ll cr = cross(ch[j] - ch[j - 1], ps[i] - ch[j]);
    if (cr < 0) {
      ch.pop_back();
      j--;
    }
    else {
      ch.push_back(ps[i]);
      i++;
      j++;
    }
  }
  return ch;
}

double width(vector<point>& ps, int n) {
  double ans = INF;
  point u = ps[1] - ps[0];
  for (int i = 0, j = 1;i < n;) {
    point v = ps[j + 1] - ps[j];
    if (cross(u, v) + EPS < 0) {
      ans = min(ans, dist(ps[j], ps[i], ps[i + 1]));
      i++;
      u = ps[i + 1] - ps[i];
    }
    else {
      j = (j + 1) % n;
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n;
  for (int t = 1;cin >> n and n;t++) {
    vector<point> ps;
    int x, y;
    loop(n) cin >> x >> y, ps.emplace_back(x, y);
    vector<point> ch = convexHull(ps, n);
    cout << "Case " << t << ": " << fixed << setprecision(2) << width(ch, ch.size() - 1) << endl;
  }
  return 0;
}

