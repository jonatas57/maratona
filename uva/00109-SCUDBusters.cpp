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
const double EPS = 1e-5;

struct point {
  int x, y;
  point(int x = 0, int y = 0) : x(x), y(y) {}
  point operator-(point p) {
    return point(x - p.x, y - p.y);
  }
  bool operator<(const point& p) const {
    return x == p.x ? y < p.y : x < p.x;
  }
};

int cross(point p, point q) {
  return p.x * q.y - p.y * q.x;
}

int cross(point a, point b, point c) {
  return cross(b - a, c - b);
}

int distsq(point p, point q = point()) {
  point del = p - q;
  return del.x * del.x + del.y * del.y;
}

double norm(point& p) {
  return sqrt(distsq(p, point()));
}

double ang(point p, point q) {
  point del = q - p;
  return acos(del.y / norm(del));
}

vector<point> convexHull(vector<point>& ps) {
  int n = ps.size();
  each(q, ps) if (q < ps[0]) swap(q, ps[0]);
  sort(ps.begin() + 1, ps.end(), [ps](point& p, point& q) {
    double a = ang(ps[0], p), b = ang(ps[0], q);
    return abs(a - b) < EPS ? distsq(p) > distsq(q) : a > b;
  });
  ps.push_back(ps[0]);

  vector<point> ch = {ps[0], ps[1]};
  int chsz = 2;
  for (int i = 2;i <= n;) {
    if (cross(ch[chsz - 2], ch[chsz - 1], ps[i]) < 0) {
      chsz--;
      ch.pop_back();
    }
    else {
      ch.push_back(ps[i]);
      chsz++;
      i++;
    }
  }
  return ch;
}

struct polygon {
  vector<point> vs;
  int sz;
  bool ok;
  polygon(vector<point>& ps) : vs(convexHull(ps)), ok(true) {
    sz = vs.size() - 1;
  }
  bool inside(point p) {
    loop(sz) if (cross(vs[i], vs[i + 1], p) < 0) return false;
    return true;
  }
  int area() {
    int a = 0;
    loop(sz) {
      a += cross(vs[i], vs[i + 1]);
    }
    return abs(a);
  }
};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n;
  vector<polygon> ks;
  while (cin >> n and n != -1) {
    vector<point> ps;
    int x, y;
    loop(n) {
      cin >> x >> y;
      ps.emplace_back(x, y);
    }
    ks.emplace_back(ps);
  }
  int x, y;
  int ans = 0;
  while (cin >> x >> y) {
    point p(x, y);
    each(k, ks) {
      if (k.ok and k.inside(p)) {
        k.ok = false;
        ans += k.area();
      }
    }
  }
  cout << fixed << setprecision(2) << ans / 2.0 << endl;
	return 0;
}

