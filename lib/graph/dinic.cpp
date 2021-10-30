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

