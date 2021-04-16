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
  vector<list<int>> adj;
  graph(int n) : size(n), adj(n) {}
  void addEdge(int a, int b) {
    adj[b].push_back(a);
  }
};

vi bfs(graph& g, int s) {
  vb visit(g.size, false);
  vi dist(g.size, -1);
  queue<int> q;
  visit[s] = true;
  dist[s] = 0;
  q.push(s);
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    each(v, g.adj[u]) {
      if (visit[v]) continue;
      visit[v] = true;
      dist[v] = dist[u] + 1;
      q.push(v);
    }
  }
  return dist;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  freopen("jumping.in", "r", stdin);

  int t;
  cin >> t;
  loop(t) {
    int n;
    cin >> n;
    graph g(n);
    loop(n) {
      int x;
      cin >> x;
      if (i - x >= 0) g.addEdge(i, i - x);
      if (i + x < n) g.addEdge(i, i + x);
    }
    vi ans = bfs(g, n - 1);
    each(x, ans) cout << x << endl;
  }
  return 0;
}

