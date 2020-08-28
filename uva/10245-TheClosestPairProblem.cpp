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
#define each(x, s)         for(auto& x : s)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

const ll mod = 1000000007;

struct point {
  double x, y;
  point(double x = 0, double y = 0) : x(x), y(y) {}
  point operator-(point p) {
    return point(x - p.x, y - p.y);
  }
  bool operator<(const point& p) const {
    return x == p.x ? y < p.y : x < p.x;
  }
};

double dist(point p, point q) {
  point del = p - q;
  return sqrt(del.x * del.x + del.y * del.y);
}

double ans;
vector<point> t;
bool cmp(point p, point q) {
  return p.y == q.y ? p.x < q.x : p.y < q.y;
}

void closest(vector<point>& ps, int l, int r) {
  if (r - l <= 3) {
    for (int i = l;i < r;i++) {
      for (int j = i + 1;j < r;j++) {
        ans = min(ans, dist(ps[i], ps[j]));
      }
    }
    sort(ps.begin() + l, ps.begin() + r, cmp);
    return;
  }
  int mid = avg(l, r);
  double midx = ps[mid].x;
  closest(ps, l, mid);
  closest(ps, mid, r);
  merge(ps.begin() + l, ps.begin() + mid, ps.begin() + mid, ps.begin() + r, t.begin(), cmp);
  copy(t.begin(), t.begin() + r - l, ps.begin() + l);

  int tsz = 0;
  for (int i = l;i < r;i++) {
    if (abs(ps[i].x - midx) < ans) {
      for (int j = tsz - 1;j >= 0 and ps[i].y - t[j].y < ans;j--) {
        ans = min(ans, dist(ps[i], t[j]));
      }
      t[tsz++] = ps[i];
    }
  }
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n;
  while (cin >> n and n) {
    vector<point> ps;
    double x, y;
    loop(n) {
      cin >> x >> y;
      ps.emplace_back(x, y);
    }
    sort(iter(ps));
    ans = INF;
    t.resize(n);
    closest(ps, 0, n);
    if (ans < 10000) {
      cout << fixed << setprecision(4) << ans << endl;
    }
    else cout << "INFINITY" << endl;
  }
	return 0;
}

