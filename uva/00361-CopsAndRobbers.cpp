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
const double PI = acos(-1.0);

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
  bool operator!=(const point& p) const {
    return x != p.x or y != p.y;
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

vector<point> convexHull(vector<point>& ps, int n) {
  if (n < 3) return ps;
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
      if (ps[i] != ch[j]) {
        ch.push_back(ps[i]);
        j++;
      }
      i++;
    }
  }
  return ch;
}

double angle(point& a, point& o, point& b) {
  point oa = a - o, ob = b - o;
  return acos((oa * ob) / (norm(oa) * norm(ob)));
}

bool onSeg(point& p, point& q, point& r) {
  point a(min(q.x, r.x), min(q.y, r.y)), b(max(q.x, r.x), max(q.y, r.y));
  return a.x <= p.x and p.x <= b.x and a.y <= p.y and p.y <= b.y;
}

bool inside(point& p, vector<point>& ps) {
  double sum = 0;
  loop((int)ps.size() - 1) {
    ll cr = cross(ps[i] - p, ps[i + 1] - p);
    if (cr == 0 and onSeg(p, ps[i], ps[i + 1])) return true;
    if (cr > 0) sum += angle(ps[i], p, ps[i + 1]);
    else sum -= angle(ps[i], p, ps[i + 1]);
  }
  return abs(abs(sum) - 2 * PI) < EPS;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int c, r, o;
  for (int t = 1;cin >> c >> r >> o and c | r | o;t++) {
    vector<point> cs, rs;
    int x, y;
    loop(c) {
      cin >> x >> y;
      cs.emplace_back(x, y);
    }
    loop(r) {
      cin >> x >> y;
      rs.emplace_back(x, y);
    }
    cs = convexHull(cs, c);
    rs = convexHull(rs, r);
    cout << "Data set " << t << ":" << endl;
    loop(o) {
      cin >> x >> y;
      point p(x, y);
      
      cout << "     Citizen at (" << p.x << "," << p.y << ") is ";
      if (c > 2 and inside(p, cs)) {
        cout << "safe." << endl;
        continue;
      }
      if (r > 2 and inside(p, rs)) {
        cout << "robbed." << endl;
        continue;
      }
      cout << "neither." << endl;
    }
    cout << endl;
  }
  return 0;
}

