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
  vi val;
  graph(int n) : size(n), adj(n), val(n) {}
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

ll xp(ll b, ll e) {
  if (e == 0) return 1;
  ll c = xp(b, e >> 1);
  c = c * c % mod;
  if (e & 1) c = c * b % mod;
  return c;
}

int solve(graph& g, int u) {
  vi dist(g.size, -1);
  dist[u] = 0;
  dfs(g, dist, u);
  int ans = 0;
  loop(g.size) {
    if (g.val[i] & 1) {
      ans ^= dist[i];
    }
  }
  return (ans ? 0 : xp(2, u + 1));
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n;
    cin >> n;
    graph g(n);
    loop(n - 1) {
      int a, b;
      cin >> a >> b;
      g.addEdge(a - 1, b - 1);
    }
    loop(n) cin >> g.val[i];/*@*/
    if (n > 1e4) continue;/*@*/
    int ans = 0;
    loop(n) ans += solve(g, i);
    cout << ans << endl;
  }
	return 0;
}

