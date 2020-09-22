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

struct graph {
  int size;
  vector<list<int>> adj;
  graph(int n) : size(n), adj(n) {}
  void addEdge(int a, int b) {
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
};

vi sz, par;
int dfs(graph& g, int u, int p = -1) {
  sz[u] = 1;
  par[u] = p;
  int maxsz = 0;
  each(v, g.adj[u]) {
    if (v == p) continue;
    int s = dfs(g, v, u);
    maxsz = max(maxsz, s);
    sz[u] += s;
  }
  return sz[u];
}

vi findCentroids(graph& g) {
  vi ans;
  sz.assign(g.size, 0);
  par.resize(g.size);
  dfs(g, 0);
  vloop(u, g.size) {
    int x = par[u] == -1 ? 0 : g.size - sz[u];
    each(v, g.adj[u]) {
      if (v == par[u]) continue;
      x = max(x, sz[v]);
    }
    if (x * 2 <= g.size) ans.push_back(u);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n;
    cin >> n;
    graph g(n);
    int u, v;
    loop(n - 1) {
      cin >> u >> v;
      g.addEdge(u - 1, v - 1);
    }
    vi cs = findCentroids(g);
    if (cs.size() == 1) {
      cout << u << " " << v << endl << u << " " << v << endl;
    }
    else {
      int hc = -1;
      each(v, g.adj[cs[1]]) {
        if (v == cs[0]) continue;
        int s = v == par[cs[1]] ? g.size - sz[cs[1]] : sz[v];
        if (hc == -1 or sz[hc] < s) hc = v;
      }
      cout << cs[1] + 1 << " " << hc + 1 << endl;
      cout << cs[0] + 1 << " " << hc + 1 << endl;
    }
  }
  return 0;
}

