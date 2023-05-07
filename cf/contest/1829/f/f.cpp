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
  vi deg;
  graph(int n) : size(n), adj(n), deg(n) {}
  void addEdge(int a, int b) {
    adj[a].push_back(b);
    adj[b].push_back(a);
    deg[a]++;
    deg[b]++;
  }
};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n, m;
    cin >> n >> m;
    graph g(n);
    loop(m) {
      int a, b;
      cin >> a >> b;
      g.addEdge(a - 1, b - 1);
    }
    int leaf = 0;
    while (g.deg[leaf] > 1) leaf++;
    vi cnt(2);
    function<void(int, int, int)> dfs = [&] (int u, int p, int dep) {
      cnt[dep & 1]++;
      each(v, g.adj[u]) {
        if (v == p) continue;
        dfs(v, u, dep + 1);
      }
    };
    dfs(leaf, -1, 0);
    int x = cnt[1];
    int y = (cnt[0] - 1) / x;
    cout << x << " " << y << endl;
  }
  return 0;
}

