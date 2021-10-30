struct hld {
  int n, idx, ch;
  vi par, sz, dist, heavy;
  vi top, id, chain;
  segtree st;

  hld(graph& g, int root = 0) : n(g.size), idx(0), ch(0), par(n), sz(n, 1), dist(n), heavy(n, -1), id(n), chain(n) {
    dist[root] = 0;
    dfs(g, root);
    top.push_back(root);
    vi a(n);
    hldec(g, a, root);
    st = segtree(a);
  }

  int dfs(graph& g, int u, int p = -1) {
    par[u] = p;
    for (auto& [v, w] : g.adj[u]) {
      if (v == par[u]) continue;
      dist[v] = dist[u] + 1;
      sz[u] += dfs(g, v, u);
      if (heavy[u] == -1 or sz[v] > sz[heavy[u]]) heavy[u] = v; 
    }
    return sz[u];
  }

  void hldec(graph& g, vi& a, int u) {
    id[u] = idx++;
    chain[u] = ch;
    if (heavy[u] != -1) hldec(g, a, heavy[u]);
    for (auto& [v, w] : g.adj[u]) {
      if (v == par[u]) continue;
      if (v == heavy[u]) {
        a[id[v]] = w;
        continue;
      }
      ch++;
      top.push_back(v);
      hldec(g, a, v);
      a[id[v]] = w;
    }
  }
  
  int query(int x, int y) {
    int ans = 0;
    x--, y--;
    while (chain[x] != chain[y]) {
      if (dist[top[chain[x]]] < dist[top[chain[y]]]) swap(x, y);
      ans += st.query(id[top[chain[x]]], id[x]);
      x = par[top[chain[x]]];
    }
    if (id[x] > id[y]) swap(x, y);
    if (id[x] != id[y]) ans += st.query(id[x] + 1, id[y]);
    return ans;
  }

  void update(int u, int v, int val) {
    if (id[u] > id[v]) swap(u, v);
    st.update(id[v], val);
  }
};

