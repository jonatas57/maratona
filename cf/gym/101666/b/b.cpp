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
  point operator-(point p) {
    return point(x - p.x, y - p.y);
  }
  point operator+(point p) {
    return point(x + p.x, y + p.y);
  }
  point operator*(double a) {
    return point(x * a, y * a);
  }
  bool operator==(const point& p) const {
    return abs(x - p.x) < EPS and abs(y - p.y) < EPS;
  }
  bool operator<(const point& p) const {
    return abs(x - p.x) < EPS ? y + EPS < p.y : x + EPS < p.x;
  }
};

istream& operator>>(istream& is, point& p) {
  int x, y;
  is >> x >> y;
  p = point(x, y);
  return is;
}
ostream& operator<<(ostream& os, const point& p) {
  os << p.x << " " << p.y;
  return os;
}

ll sqnorm(point& p) {
  ll x = p.x, y = p.y;
  return x * x + y * y;
}

struct circle {
  point o;
  ll r;
  circle(point o = point(), ll r = 0) : o(o), r(r) {}
  bool operator==(const circle& c) const {
    return o == c.o and r == c.r;
  }
  bool operator<(const circle& c) const {
    return o == c.o ? r < c.r : o < c.o;
  }
};

struct line {
  double a, b, c;
  line(ll x = 0, ll y = 0, ll z = 0) : a(x), b(y), c(z) {}
  line(point p, point q) {
    point del = p - q;
    a = -del.y;
    b = del.x;
    c = -(a * p.x + b * p.y);
  }
};

vector<point> intersect(circle& c, line& l) {
  double lc = l.c + (l.a * c.o.x + l.b * c.o.y);
  double aux = l.a * l.a + l.b * l.b;
  double d0 = lc * lc / aux;
  if (sqrt(d0) > EPS + c.r) return {};
  point p(-l.a * lc / aux, -l.b * lc / aux);
  if (abs(d0 - c.r * c.r) < EPS) return {p + c.o};
  point v(-l.b, l.a);
  double d = c.r * c.r - d0;
  double m = sqrt(d / aux);
  vector<point> ans;
  v = v * m;
  ans.push_back(p + v + c.o);
  ans.push_back(p - v + c.o);
  return ans;
}

vector<point> intersect(circle& c, circle& d) {
  point del = d.o - c.o;
  line l(2 * del.x, 2 * del.y, sqnorm(c.o) - sqnorm(d.o) - c.r * c.r + d.r * d.r);
  auto ans = intersect(d, l);
  return ans;
}

double dist(point& a, point& b) {
  point del = a - b;
  return sqrt(del.x * del.x + del.y * del.y);
}

struct graph {
  int size;
  map<point, int> conv;
  vector<list<pair<int, double>>> adj;
  graph() : size(0) {}
  void addEdge(point& a, point& b) {
    int x = addNode(a);
    int y = addNode(b);
    double d = dist(a, b);
    adj[x].emplace_back(y, d);
    adj[y].emplace_back(x, d);
  }
  int addNode(point& p) {
    if (!conv.count(p)) {
      conv[p] = size++;
      adj.emplace_back();
    }
    return conv[p];
  }
};

double dijkstra(graph& g) {
  vector<double> dist(g.size, INF);
  vb visit(g.size, false);
  priority_queue<pair<double, int>> q;
  dist[0] = 0;
  q.emplace(0, 0);
  while (!q.empty()) {
    auto [d, u] = q.top();
    q.pop();
    if (visit[u]) continue;
    visit[u] = true;
    for (auto& [v, w] : g.adj[u]) {
      if (visit[v]) continue;
      if (dist[v] > EPS + dist[u] + w) {
        dist[v] = dist[u] + w;
        q.emplace(-dist[v], v);
      }
    }
  }
  return abs(dist[1] - INF) < EPS ? -1 : dist[1];
}

double max(double a, double b) {
  return a + EPS < b ? b : a;
}

double min(double b, double a) {
  return a + EPS < b ? a : b;
}

bool iscovered(point p, point q, vector<circle>& cs) {
  line l(p, q);
  point del = q - p;
  priority_queue<pair<double, double>> segs;
  each(c, cs) {
    pair<double, double> seg(-1, 0);
    each(a, intersect(c, l)) {
      point b = a - p;
      double rat = min(0.0, max(-1, abs(del.x) < EPS ? -b.y / del.y : -b.x / del.x));
      seg.first = max(seg.first, rat);
      seg.second = min(seg.second, rat);
    }
    if (seg.first + EPS > seg.second) segs.push(seg);
  }
  if (segs.empty()) return false;
  auto s = segs.top();
  segs.pop();
  while (!segs.empty()) {
    auto t = segs.top();
    segs.pop();
    if (abs(t.first) < EPS + abs(s.second)) {
      s.second = t.second;
    }
    else return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  point a, b;
  cin >> a >> b;
  int n;
  cin >> n;
  vector<circle> cs;
  loop(n) {
    point p;
    ll r;
    cin >> p >> r;
    cs.emplace_back(p, r);
  }
  sort(iter(cs));
  int sz;
  cs.resize(sz = unique(iter(cs)) - cs.begin());
  vector<point> ps = {a, b};
  int psz = 2;
  loop(sz) {
    vloop(j, i) {
      each(p, intersect(cs[i], cs[j])) {
        ps.push_back(p);
        psz++;
      }
    }
  }
  graph g;
  g.addNode(a);
  g.addNode(b);
  loop(psz) {
    vloop(j, i) {
      if (ps[i] == ps[j]) continue;
      if (iscovered(ps[i], ps[j], cs)) {
        g.addEdge(ps[i], ps[j]);
      }
    }
  }
  double ans = dijkstra(g);
  if (ans < 0) cout << "impossible" << endl;
  else cout << fixed << setprecision(11) << ans << endl;
  return 0;
}

