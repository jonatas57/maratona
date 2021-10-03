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
#define avg(l, r)          (l + r) >> 1
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

const ll mod = 1000000007;
const double EPS = 1e-7;
const double PI = acos(-1);

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

ii solve(graph& g, int x, int u = 0, int p = -1) {
  int erased = 0;
  int xu = g.val[u];
  each(v, g.adj[u]) {
    if (v == p) continue;
    auto [er, xr] = solve(g, x, v, u);
    xu ^= xr;
    erased += er;
  }
  if (xu == x and u) {
    erased++;
    xu = 0;
  }
  return {erased, xu};
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n, k;
    cin >> n >> k;
    graph g(n);
    int x = 0;
    loop(n) cin >> g.val[i], x ^= g.val[i];
    loop(n - 1) {
      int u, v;
      cin >> u >> v;
      g.addEdge(u - 1, v - 1);
    }
    if (!x) cout << "YES" << endl;
    else {
      cout << (solve(g, x).first >= 2 and k > 2 ? "YES" : "NO") << endl;
    }
  }
  return 0;
}

