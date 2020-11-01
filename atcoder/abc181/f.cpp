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
  bool operator==(const point& p) const {
    return x == p.x and y == p.y;
  }

  friend istream& operator>>(istream& is, point& p) {
    is >> p.x >> p.y;
    return is;
  }
};

double norm(point p) {
  return sqrt(p * p);
}

double dist(point& a, point& b) {
  return norm(a - b);
}

struct graph {
  int size;
  vector<list<pair<int, double>>> adj;
  graph(int n) : size(n), adj(n) {}
  void addEdge(int a, int b, double w) {
    adj[a].emplace_back(b, w);
    adj[b].emplace_back(a, w);
  }
};

struct dsu {
  vi id, sz;

  dsu(int n) : id(n), sz(n, 1) {
    loop(n) id[i] = i;
  }

  int find(int x) {
    return x == id[x] ? x : id[x] = find(id[x]);
  }

  bool join(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (sz[a] > sz[b]) swap(a, b);
    id[a] = id[b];
    sz[b] += sz[a];
    return true;
  }
};

bool check(graph& g, double r) {
  dsu uf(g.size);
  loop(g.size) {
    for (auto& [v, w] : g.adj[i]) {
      if (w < EPS + r + r) uf.join(i, v);
    }
  }
  return uf.find(g.size - 2) != uf.find(g.size - 1);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n;
  cin >> n;
  vector<point> ps(n);
  loop(n) cin >> ps[i];
  sort(iter(ps));
  graph g(n + 2);
  loop(n) {
    vloop(j, i) {
      g.addEdge(i, j, dist(ps[i], ps[j]));
    }
    g.addEdge(i, n, 100 - ps[i].y);
    g.addEdge(i, n + 1, ps[i].y + 100);
  }
  double l = 0, r = 100;
  while (l + EPS < r) {
    double mid = avg(l, r);
    if (check(g, mid)) l = mid;
    else r = mid;
  }
  cout << fixed << setprecision(5) << l << endl;
  return 0;
}

