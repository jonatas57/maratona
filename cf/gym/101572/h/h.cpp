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
const double EPS = 1e-13;
const double VOL = 2 * acos(-1);

struct edge {
  int u, v, cap, flow;
  edge(int a, int b, int c, int d) : u(a), v(b), cap(c), flow(d) {}
};

struct graph {
  int size;
  vector<vi> adj;
  vector<edge> es;
  vi ptr, dist;
  int m;

  graph(int n) : size(n), adj(n), m(0) {}
  void addEdge(int a, int b, int f) {
    es.emplace_back(a, b, f, 0);
    es.emplace_back(b, a, 0, 0);
    adj[a].push_back(m++);
    adj[b].push_back(m++);
  }
};

bool bfs(graph& g, int s, int t) {
  g.dist.assign(g.size, -1);
  queue<int> q;
  q.push(s);
  g.dist[s] = 0;
  while (!q.empty() and g.dist[t] == -1) {
    int u = q.front();
    q.pop();
    each(id, g.adj[u]) {
      int v = g.es[id].v;
      if (g.dist[v] == -1 and g.es[id].flow < g.es[id].cap) {
        q.push(v);
        g.dist[v] = g.dist[u] + 1;
      }
    }
  }
  return g.dist[t] != -1;
}

int dfs(graph& g, int u, int t, int flow) {
  if (!flow) return 0;
  if (u == t) return flow;
  for (;g.ptr[u] < (int)g.adj[u].size();g.ptr[u]++) {
    int id = g.adj[u][g.ptr[u]], v = g.es[id].v;
    if (g.dist[v] != g.dist[u] + 1) continue;
    int pushed = dfs(g, v, t, min(flow, g.es[id].cap - g.es[id].flow));
    if (pushed) {
      g.es[id].flow += pushed;
      g.es[id ^ 1].flow -= pushed;
      return pushed;
    }
  }
  return 0;
}

int dinic(graph& g, int s, int t) {
  int flow = 0;
  for (;bfs(g, s, t);) {
    g.ptr.assign(g.size, 0);
    while (int pushed = dfs(g, s, t, INF)) flow += pushed;
  }
  return flow;
}

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
  friend ostream& operator<<(ostream& os, point& p) {
    os << p.x << " " << p.y;
    return os;
  }
};

double norm(point& p) {
  return sqrt(p * p);
}

double angle(point& a) {
  return acos(a.x / norm(a)) * (a.y < -EPS ? -1 : 1);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n, m;
  cin >> n >> m;
  graph g(n + m + 2);
  vector<tuple<double, int, point>> ps, ts;
  int sink = n + m + 1;
  point p;
  loop(n) {
    cin >> p;
    g.addEdge(0, i + 1, 1);
    ps.emplace_back(angle(p), i + 1, p);
  }
  loop(m) {
    int c;
    cin >> p >> c;
    g.addEdge(n + i + 1, sink, c);
    ts.emplace_back(angle(p), n + i + 1, p);
  }
  sort(iter(ps));
  sort(iter(ts));
  ts.push_back(ts[0]);
  get<0>(ts[m]) += VOL;
  for (int i = 0, j = -1;i < n;i++) {
    while (get<0>(ts[j + 1]) < EPS + get<0>(ps[i])) j++; 
    auto [angp, idp, p] = ps[i];
    auto [angl, idl, l] = ts[(j + m) % m];
    double nx = get<0>(ts[j + 1]) - angp;
    double pv = angp - angl;
    if (pv < -EPS) pv += VOL;
    if (nx < pv + EPS) g.addEdge(idp, get<1>(ts[(j + 1) % m]), 1);
    if (pv < nx + EPS) g.addEdge(idp, idl, 1);
  }
  int flow = dinic(g, 0, sink);
  cout << flow << endl;
  each(id, g.adj[0]) {
    if (g.es[id].cap == g.es[id].flow) {
      int u = g.es[id].v;
      each(id2, g.adj[u]) {
        if (g.es[id2].cap == g.es[id2].flow) {
          cout << u - 1 << " " << g.es[id2].v - n - 1 << endl;
        }
      }
    }
  }
  return 0;
}

