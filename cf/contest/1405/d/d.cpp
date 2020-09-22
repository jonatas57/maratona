#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define INFLL              0x3f3f3f3f3f3f3f3f
#define each(x, s)         for(auto& x : s)
#define loop(x)	           for(int i = 0;i < x;i++)
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

void dfs(graph& g, vi& dist, int u, int p = -1) {
  each(v, g.adj[u]) {
    if (v == p) continue;
    dist[v] = dist[u] + 1;
    dfs(g, dist, v, u);
  }
}

int diameter(graph& g) {
  vi dist(g.size, 0);
  dfs(g, dist, 0);
  int f = 0;
  loop(g.size) {
    if (dist[i] > dist[f]) f = i;
  }
  loop(g.size) dist[i] = 0;
  dfs(g, dist, f);
  int ans = 0;
  loop(g.size) ans = max(ans, dist[i]);
  return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    graph g(n);
    int u, v;
    loop(n - 1) {
      cin >> u >> v;
      g.addEdge(u - 1, v - 1);
    }
    int d = diameter(g);
    vi dist(g.size, 0);
    dfs(g, dist, a - 1);
    cout << (da + da < min(d, db) and dist[b - 1] > da ? "Bob" : "Alice") << endl;
  }
	return 0;
}

