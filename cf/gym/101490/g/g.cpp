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

struct point {
  ll x, y;
  point(ll x = 0, ll y = 0) : x(x), y(y) {}
  point operator+(const point& p) const {
    return point(x + p.x, y + p.y);
  }
  point operator-(const point& p) const {
    return point(x - p.x, y - p.y);
  }
  ll operator*(const point& p) const {
    return x * p.x + y * p.y;
  }
  point operator*(const ll a) const {
    return point(a * x, a * y);
  }
  ll operator^(const point& p) const {
    return x * p.y - y * p.x;
  }

  bool operator<(const point& p) const {
    return x == p.x ? x < p.x : y < p.y;
  }
  bool operator!=(const point& p) const {
    return x != p.x or y != p.y;
  }
  bool operator==(const point& p) const {
    return x == p.x and y == p.y;
  }

  friend istream& operator>>(istream& is, point& p) {
    is >> p.x >> p.y;
    return is;
  }
  friend ostream& operator<<(ostream& os, point p) {
    os << p.x << " " << p.y;
    return os;
  }
};

struct seg {
  point p, q;
  ll a, b, c;
  seg() {}
  seg(point x, point y) : p(x), q(y) {
    if (q < p) swap(p, q);
    coef();
  }
  void coef() {
    point del = q - p;
    a = del.y;
    b = -del.x;
    c = -(a * p.x + b * p.y);
    ll m = gcd(a, gcd(b, c));
    if (a < 0) m = -m;
    if (m) {
      a /= m;
      b /= m;
      c /= m;
    }
  }
  bool inside(point& x) {
    if (p == q) return x == p;
    return a * x.x + b * x.y + c == 0;
  }
  bool ispoint() {
    return p == q;
  }
};

vector<point> dirs = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
vector<seg> square(point p, ll d) {
  vector<point> ps;
  each(q, dirs) ps.push_back(p + (q * d));
  ps.push_back(ps[0]);
  vector<seg> ans;
  loop(4) ans.emplace_back(ps[i], ps[i + 1]);
  return ans;
}

bool onSeg(point& p, seg& s) {
  if ((p - s.p) ^ (s.q - s.p)) return false;
  return min(s.p.x, s.q.x) <= p.x and p.x <= max(s.p.x, s.q.x);
}

bool isparallel(seg& s, seg& t) {
  if ((s.a or s.b) and (t.a or t.b)) return s.a == t.a and s.b == t.b;
  return true;
}

bool intersect(seg& s, seg& t, vector<seg>& is) {
  bool ok = false;
  if (isparallel(s, t)) {
    if (s.inside(t.p) or t.inside(s.p)) {
      point p = max(s.p, t.p);
      point q = min(s.q, t.q);
      is.emplace_back(p, q);
      ok = true;
    }
  }
  else {
    point del = t.q - t.p;
    ll cr = t.q ^ t.p;
    ll u = abs(del.y * s.p.x - del.x * s.p.y + cr);
    ll v = abs(del.y * s.q.x - del.x * s.q.y + cr);
    ll x = s.p.x * v + s.q.x * u, y = s.p.y * v + s.q.y * u;
    ll z = u + v;
    if (z and x % z == 0 and y % z == 0) {
      point p(x / z, y / z);
      if (onSeg(p, s) and onSeg(p, t)) {
        is.emplace_back(p, p);
        ok = true;
      }
    }
  }
  return ok;
}

bool join(seg& a, seg& b) {
  bool joined = false;
  if (a.ispoint()) {
    if (a.p == b.p) a.q = b.q, joined = true;
    else if (a.p == b.q) a.q = b.p, joined = true;
  }
  else if (b.ispoint() and (a.p == b.p or a.q == b.p)) joined = true;
  else if (a.p == b.p and a.q == b.q) joined = true;
  a.coef();
  return joined;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n;
  cin >> n;
  point p;
  ll d;
  vector<seg> ans;
  bool ok = true;
  loop(n) {
    cin >> p >> d;
    vector<seg> sq = square(p, d), aux;
    if (ans.empty() and ok) ans.swap(sq);
    else {
      each(s, sq) {
        each(t, ans) {
          intersect(s, t, aux);
        }
      }
      if (aux.empty()) ok = false;
      ans.swap(aux);
    }
    int sz = ans.size();
    for (int i = 0;i < sz;i++) {
      for (int j = i + 1;j < sz;j++) {
        if (join(ans[i], ans[j])) {
          swap(ans[j], ans[sz - 1]);
          j--;
          sz--;
        }
      }
    }
    ans.resize(sz);
  }
  if (ans.empty()) cout << "impossible" << endl;
  else if (ans.size() > 1 or ans[0].p != ans[0].q) cout << "uncertain" << endl;
  else cout << ans[0].p << endl;
  return 0;
}

