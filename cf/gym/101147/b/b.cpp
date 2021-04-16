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

struct graph {
  int size;
  vector<list<pair<int, double>>> adj;
  graph(int n) : size(n), adj(n) {}
  void addEdge(int a, int b, double c) {
    adj[a].emplace_back(b, c);
    adj[b].emplace_back(a, c);
  }
};

double dijkstra(graph& g, int s, int t) {
  vector<double> dist(g.size, -1);
  vb visit(g.size, false);
  priority_queue<pair<double, int>> q;
  dist[s] = 0;
  q.emplace(0, s);
  while (!q.empty()) {
    auto [d, u] = q.top();
    q.pop();
    if (visit[u]) continue;
    visit[u] = true;
    dist[u] = abs(d);
    for (auto& [v, w] : g.adj[u]) {
      if (visit[v]) continue;
      q.emplace(-dist[u] - w, v);
    }
  }
  return dist[t];
}

ll L, U;
struct rect {
  ll t, b, l, r;
  rect(ll h, ll w, ll d, ll k) {
    t = d + h;
    b = d;
    l = k ? U - w : 0;
    r = k ? U : w;
  }
};

ll dist(ll a, ll b, ll c, ll d) {
  if (max(a, c) <= min(b, d)) return 0;
  if (b < c) return c - b;
  return a - d;
}

double dist(rect& a, rect& b) {
  ll x = dist(a.b, a.t, b.b, b.t);
  ll y = dist(a.l, a.r, b.l, b.r);
  return sqrt(x * x + y * y);
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  freopen("street.in", "r", stdin);

  int t;
  cin >> t;
  loop(t) {
    int n;
    cin >> n >> L >> U;
    graph g(n + 2);
    vector<rect> rs;
    ll h, w, d, k;
    loop(n) {
      cin >> h >> w >> d >> k;
      rs.emplace_back(h, w, d, k);
      g.addEdge(i, n, d);
      g.addEdge(i, n + 1, L - rs[i].t);
      vloop(j, i) {
        g.addEdge(i, j, dist(rs[i], rs[j]));
      }
    }
    cout << fixed << setprecision(6) << dijkstra(g, n, n + 1) << endl;
  }
  return 0;
}

