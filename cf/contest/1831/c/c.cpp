#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef vector<bool>       vb;
typedef pair<int, int>     ii;

const int INF = 0x3f3f3f3f;
const ll  INFLL = 0x3f3f3f3f3f3f3f3fll;

#define each(x, s)  for(auto& x : s)
#define loop(x)     for(int i = 0;i < x;i++)
#define vloop(v, x) for(int v = 0;v < x;v++)
#define iter(a)     a.begin(), a.end()
#define riter(a)    a.rbegin(), a.rend()
#define endl        "\n"
#define avg(l, r)   (l + r) / 2

struct graph {
  int size;
  vector<vector<ii>> adj;
  graph(int n) : size(n), adj(n) {}
  void addEdge(int a, int b, int c) {
    adj[a].emplace_back(b, c);
    adj[b].emplace_back(a, c);
  }
};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n;
    cin >> n;
    graph g(n);
    loop(n - 1) {
      int u, v;
      cin >> u >> v;
      g.addEdge(u - 1, v - 1, i);
    }
    int ans = 1;
    queue<tuple<int, int, int>> q;
    vb vis(n);
    vi ids(n), rs(n, 1);
    q.emplace(0, 0, 0);
    vis[0] = true; 
    while (!q.empty()) {
      auto [u, id, p] = q.front();
      q.pop();
      ids[u] = id;
      if (ids[p] > id) {
        rs[u] = rs[p] + 1;
        ans = max(ans, rs[u]);
      }
      else rs[u] = rs[p];
      for (auto& [v, w] : g.adj[u]) {
        if (v == p) continue;
        q.emplace(v, w, u);
      }
    }
    cout << ans << endl;
  }
  return 0;
}

