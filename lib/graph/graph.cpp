struct graph {
  int size;
  vector<list<int>> adj;
  graph(int n) : size(n), adj(n) {}
  void addEdge(int a, int b) {
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
};

