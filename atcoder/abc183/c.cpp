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

struct graph {
  int size;
  vector<vector<ll>> adj;
  graph(int n) : size(n), adj(n, vector<ll>(n)) {}
};

vb vis;

ll dfs(graph& g, int k, int u = 0, int qtd = 1) {
  if (qtd == g.size) return g.adj[u][0] == k;
  vis[u] = true;
  ll ans = 0;
  vloop(v, g.size) {
    if (vis[v]) continue;
    if (k >= g.adj[u][v]) ans += dfs(g, k - g.adj[u][v], v, qtd + 1);
  }
  vis[u] = false;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n, k;
  cin >> n >> k;
  graph g(n);
  loop(n) vloop(j, n) {
    cin >> g.adj[i][j];
  }
  vis.assign(n, false);
  cout << dfs(g, k) << endl;
  return 0;
}

