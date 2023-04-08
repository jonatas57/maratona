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
  vector<vi> adj;
  graph(int n) : size(n), adj(n) {}
  void addEdge(int a, int b) {
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n, m;
  cin >> n >> m;
  graph g(n);
  vector<ll> a(n);
  loop(n) cin >> a[i];
  loop(n - 1) {
    int u, v;
    cin >> u >> v;
    g.addEdge(u - 1, v - 1);
  }
  vi w(n), par(n);
  vector<ll> acc(n);
  vector<multiset<ii>> ss(n);
  function<void(int, int)> dfs = [&] (int u, int p) {
    w[u] = 1;
    par[u] = p;
    acc[u] = a[u];
    each(v, g.adj[u]) {
      if (v == p) continue;
      dfs(v, u);
      w[u] += w[v];
      acc[u] += acc[v];
      ss[u].emplace(-w[v], v);
    }
  };
  dfs(0, -1);
  loop(m) {
    int op, x;
    cin >> op >> x;
    x--;
    if (op == 1) {
      cout << acc[x] << endl;
    }
    else {
      if (ss[x].empty()) continue;
      int fa = par[x];
      int son = ss[x].begin()->second;
      ss[x].erase(ss[x].begin());
      ss[fa].erase(ss[fa].find(make_pair(-w[x], x)));
      acc[x] -= acc[son];
      acc[son] += acc[x];
      w[x] -= w[son];
      w[son] += w[x];
      par[son] = fa;
      par[x] = son;
      ss[fa].emplace(-w[son], son);
      ss[son].emplace(-w[x], x);
    }
  }
  return 0;
}

