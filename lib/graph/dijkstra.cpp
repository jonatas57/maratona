void dijkstra(graph& g, int a, int b) {
  vi dist(g.size, INF);
  vb visit(g.size, false);
  priority_queue<ii> q;
  dist[a] = 0;
  q.emplace(0, a);
  while (!q.empty()) {
    auto& [d, u] = q.top();
    q.pop();
    if (visit[u]) continue;
    visit[u] = true;
    for (auto& [v, w] : g.adj[u]) {
      if (visit[v]) continue;
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        q.emplace(-dist[v], v);
      }
    }
  }
  return dist[b];
}

