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
  vector<vector<int>> adj;
  vi deg;
  graph() : adj(26, vi(26, 0)), deg(26, 0) {}
  void addEdge(int a, int b, int w) {
    adj[a][b] = adj[b][a] = w;
    deg[a]++;
    deg[b]++;
  }
  void clear() {
    adj.assign(26, vi(26, 0));
    deg.assign(26, 0);
  }
  ii getOdd() {
    vi a;
    loop(26) {
      if (deg[i] & 1) {
        a.push_back(i);
      }
    }
    if (a.empty()) return {0, 0};
    else return {a[0], a[1]};
  }
};

int dijkstra(graph& g, int s, int t) {
  vi dist(26, INF);
  vb visit(26, false);
  priority_queue<ii> q;
  dist[s] = 0;
  q.emplace(0, s);
  while (!q.empty()) {
    int d, u;
    tie(d, u) = q.top();
    q.pop();
    if (visit[u]) continue;
    visit[u] = true;
    if (u == t) return abs(d);
    for (int v = 0;v < 26;v++) {
      int w = g.adj[u][v];
      if (visit[v] or !w) continue;
      if (dist[v] > dist[u] + w) {
        dist[v] = dist[u] + w;
        q.emplace(-dist[v], v);
      }
    }
  }
  return 0;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  string s;
  graph g;
  int sum = 0;
  while (cin >> s) {
    if (s == "deadend") {
      int u, v;
      tie(u, v) = g.getOdd();
      cout << sum + dijkstra(g, u, v) << endl;
      g.clear();
      sum = 0;
    }
    else {
      int w = s.length();
      int a = s[0] - 'a';
      int b = s[w - 1] - 'a';
      sum += w;
      g.addEdge(a, b, w);
    }
  }
	return 0;
}

