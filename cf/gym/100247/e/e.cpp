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

string perm;
vb ok;

bool dfs(graph& g, int u = 0, int p = -1) {
  bool leaf = true, all = true;
  each(v, g.adj[u]) {
    if (v == p) continue;
    leaf = false;
    if (perm[v] == '0') perm[v] = perm[u];
    all &= dfs(g, v, u);
  }
  if (leaf) ok[u] = perm[u] == '+';
  else if (all) {
    each(v, g.adj[u]) {
      if (v == p) continue;
      ok[v] = false;
    }
    ok[u] = true;
  }
  return ok[u];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n;
  cin >> n;
  cin >> perm;
  graph g(n);
  int a, b;
  loop(n - 1) {
    cin >> a >> b;
    g.addEdge(a - 1, b - 1);
  }
  if (perm[0] == '0') perm[0] = '-';
  ok.resize(n, false);
  dfs(g);
  vi ans;
  loop(n) if (ok[i]) ans.push_back(i + 1);
  cout << ans.size() << endl;
  each(x, ans) cout << x << " ";
  cout << endl;
  return 0;
}

