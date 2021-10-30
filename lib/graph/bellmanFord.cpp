int bellmanFord(graph& g) {
  vb vis(g.size, false);
  vector<ll> dist(g.size, INFLL);
  dist[0] = 0;
  loop(g.size) {
    vloop(u, g.size) {
      for (auto& [v, w] : g.adj[u]) {
        if (dist[v] > dist[u] + w) {
          dist[v] = dist[u] + w;
          par[v] = u;
          if (i == g.size - 1) return v;
        }
      }
    }
  }
  return -1;
}

