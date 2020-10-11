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

typedef tuple<int, int, int, int, int> tup;

struct graph {
  int size;
  vector<list<tup>> adj;
  graph(int n) : size(n), adj(n) {}
  void addEdge(int a, int b, int t, int c, int f, int s) {
    adj[a].emplace_back(b, t, c, f, s);
  }
};

ii dijkstra(graph& g) {
  vi dist(g.size, INF), cost(g.size, INF);
  vector<vb> visit(g.size, vb(5e5, false));
  priority_queue<tuple<int, int, int>> q;
  dist[0] = cost[0] = 0;
  q.emplace(0, 0, 0);
  while (!q.empty()) {
    auto [t, c, u] = q.top();
    q.pop();
    dist[u] = t = -t;
    cost[u] = c = -c;
    if (u == g.size - 1) return {dist[u], cost[u]};
    if (visit[u][t]) continue;
    visit[u][t] = true;
    for (auto& [v, d, w, f, s] : g.adj[u]) {
      int k = (t - s + f) / f;
      int at = s + f * k + d;
      if (visit[v][at]) continue;
      auto [nt, nc] = min(make_pair(dist[v], cost[v]), make_pair(at, c + w));
      q.emplace(-nt, -nc, v);
    }
  }
  return {dist[g.size - 1], cost[g.size - 1]};
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n, m;
  cin >> n >> m;
  graph g(n);
  loop(m) {
    int a, b, t, c, f, s;
    cin >> a >> b >> t >> c >> f >> s;
    g.addEdge(a - 1, b - 1, t, c, f, s);
  }
  auto [tm, cost] = dijkstra(g);
  cout << tm << " " << cost << endl;
  return 0;
}

