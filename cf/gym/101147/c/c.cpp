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

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#ifndef MEUPC
  freopen("wall.in", "r", stdin);
#endif

  int t;
  cin >> t;
  loop(t) {
    int n, m, p;
    cin >> n >> m >> p;
    vector<vi> a(n, vi(m + 1, 0));
    double x, y;
    loop(p) {
      cin >> x >> y;
      double d = sqrt((n * n / 4.0) - (n * n / 4.0 - x * (n - x)));
      int j = max(0.0, ceil(y - d));
      a[(int)x][j]++;
    }
    graph g(n + m + 3);
    loop(n) {
      g.addEdge(n + m + 1, i, 1);
      vloop(j, m + 1) {
        if (a[i][j]) g.addEdge(i, j + n, 1);
      }
    }
    loop(m + 1) g.addEdge(i + n, n + m + 2, 1);
    cout << dinic(g, n + m + 1, n + m + 2) << endl;
  }
  return 0;
}

