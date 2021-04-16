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
  friend ostream& operator<<(ostream& os, point p) {
    os << p.x << " " << p.y;
    return os;
  }
};

int ccw(point& a, point& b, point& c) {
	double cr = (b - a) ^ (c - a);
	return cr ? (cr > 0 ? 1 : -1) : 0;
}

bool onSegment(point& p, point& q, point& r) {
	return q.x <= max(p.x, r.x) and q.x >= min(p.x, r.x) and q.y <= max(p.y, r.y) and q.y >= min(p.y, r.y);
}

bool intersect(point& a, point& b, point&& p, point&& q) {
	int c1 = ccw(a, b, p), c2 = ccw(a, b, q), c3 = ccw(p, q, a), c4 = ccw(p, q, b);
	if (c1 != c2 and c3 != c4) return true;
	if (c1 == 0 and onSegment(a, p, b)) return true;
	if (c2 == 0 and onSegment(a, q, b)) return true;
	if (c3 == 0 and onSegment(p, a, q)) return true;
	if (c4 == 0 and onSegment(p, b, q)) return true;
	return false;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n;
  cin >> n;
  vector<vector<point>> ps(n);
  vi aux(n), sz(n);
  double ans = 0;
  vector<ll> maxx(n), minx(n);
  loop(n) {
    int k, x, y;
    cin >> k;
    sz[i] = k;
    int l = 0, r = 0;
    vloop(j, k) {
      cin >> x >> y;
      l = min(l, x);
      r = max(r, x);
      ps[i].emplace_back(x, y);
      if (j and ps[i][j].y == ps[i][j - 1].y) aux[i] = j;
    }
    ps[i].push_back(ps[i][0]);
    ans += (maxx[i] = r) - (minx[i] = l);
  }

  vector<vector<double>> del(n, vector<double>(n, 0));
  loop(n) {
    vloop(j, n) {
      if (i == j) continue;
      double l = min(ps[i][1].x, ps[i][aux[i] - 1].x) - minx[j] , r = maxx[i] - minx[j];
      while (l + EPS < r) {
        point mid(avg(l, r));
        
        bool inter = false;
        for (int x = aux[i] - 1, y = aux[j];!inter and x > 1 and y < sz[j];) {
          inter = intersect(ps[i][x], ps[i][x - 1], ps[j][y] + mid, ps[j][y + 1] + mid);
          if (ps[i][x - 1].y + EPS < ps[j][y + 1].y) y++;
          else x--;
        }
        if (inter) l = mid.x;
        else r = mid.x;
      }
      del[i][j] = maxx[i] - minx[j] - l;
    }
  }

  vector<vector<double>> dp(1 << n, vector<double>(n, 0));
  for (int m = 0;m < (1 << n);m++) {
    for (int i = 0, m2 = 1;i < n;i++, m2 <<= 1) {
      if (!(m & m2)) continue;
      for (int j = 0, m3 = 1;j < n;j++, m3 <<= 1) {
        if (!(m & m3) or i == j) continue;
        dp[m][i] = max(dp[m][i], dp[m - m2][j] + del[j][i]);
      }
    }
  }
  double bonus = 0;
  loop(n) bonus = max(bonus, dp.back()[i]);
  ans -= bonus;
  
  cout << fixed << setprecision(3) << ans << endl;
  return 0;
}

