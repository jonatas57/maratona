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
const double PI = acos(-1);

struct point {
  ll x, y;
  point(ll x = 0, ll y = 0) : x(x), y(y) {}
  bool operator<(const point& p) const {
    return x == p.x ? y < p.y : x < p.x;
  }
  ll operator^(const point p) const {
    return x * p.y - y * p.x;
  }
  point operator-(const point& p) const {
    return point(x - p.x, y - p.y);
  }
  ll operator*(const point& p) const {
    return x * p.x + y * p.y;
  }
};

ll distsq(point& p, point& q) {
  point del = p - q;
  return del * del;
}

vector<point> convexHull(vector<point>& ps) {
  int n = ps.size();
  sort(iter(ps));
  point pivo = ps[0];
  sort(ps.begin() + 1, ps.end(), [&pivo](point& p, point& q) {
    point a = p - pivo, b = q - pivo;
    ll cr = a ^ b;
    return cr ? cr > 0 : distsq(pivo, p) > distsq(pivo, q);
  });
  ps.push_back(pivo);
  vector<point> ch = {ps[0], ps[1]};
  for (int i = 2, j = 1;i <= n;) {
    ll cr = (ch[j] - ch[j - 1]) ^ (ps[i] - ch[j]);
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

int orientation(point& o, point& a, point& b) {
  ll cr = (a - o) ^ (b - o);
  return cr ? cr / abs(cr) : 0;
}

bool onseg(point& p, point a, point b) {
  if (a.x > b.x) swap(a.x, b.x);
  if (a.y > b.y) swap(a.y, b.y);
  return a.x <= p.x and p.x <= b.x and a.y <= p.y and p.y <= b.y;
}

bool intersect(point& a, point& b, point& p, point& q) {
  int x = orientation(a, b, p);
  int y = orientation(a, b, q);
  int w = orientation(p, q, a);
  int z = orientation(p, q, b);
  if (!x and onseg(p, a, b)) return true;
  if (!y and onseg(q, a, b)) return true;
  if (!w and onseg(a, p, q)) return true;
  if (!z and onseg(b, p, q)) return true;
  return (x != y) and (w != z);
}

double norm(point& p) {
  return sqrt(p * p);
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
    ll cr = (ps[i] - p) ^ (ps[i + 1] - p);
    if (cr == 0 and onSeg(p, ps[i], ps[i + 1])) return true;
    if (cr > 0) sum += angle(ps[i], p, ps[i + 1]);
    else sum -= angle(ps[i], p, ps[i + 1]);
  }
  return abs(abs(sum) - 2 * PI) < EPS;
}

bool intersect(vector<point>& ps, vector<point>& qs) {
  loop((int)ps.size() - 1) {
    vloop(j, (int)qs.size() - 1) {
      if (intersect(ps[i], ps[i + 1], qs[j], qs[j + 1])) return true;
    }
  }
  each(p, ps) if (inside(p, qs)) return true;
  each(q, qs) if (inside(q, ps)) return true;
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int m, c;
  while (cin >> m >> c and m | c) {
    int x, y;
    vector<point> ms, cs;
    loop(m) cin >> x >> y, ms.emplace_back(x, y);
    loop(c) cin >> x >> y, cs.emplace_back(x, y);
    ms = convexHull(ms);
    cs = convexHull(cs);
    cout << (intersect(ms, cs) ? "No" : "Yes") << endl;
  }
  return 0;
}

