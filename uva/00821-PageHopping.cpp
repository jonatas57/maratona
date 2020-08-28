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
  vector<vi> adj;
  graph() : adj(100, vi(100, INF)) {}
  void addEdge(int a, int b) {
    adj[a][b] = 1;
  }
};

vector<vi> floyd(graph& g) {
  vector<vi> dists = g.adj;
  vloop(k, 100) {
    loop(100) vloop(j, 100) {
      dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
    }
  }
  return dists;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  for (int tc = 1;;tc++) {
    graph g;
    bool ok = false;
    int a, b;
    while (cin >> a >> b and a | b) {
      a--, b--;
      g.addEdge(a, b);
      ok = true;
    }
    if (!ok) break;
    vector<vi> dists = floyd(g);
    int sum = 0, tot = 0;
    loop(100) {
      vloop(j, 100) {
        if (i == j or dists[i][j] == INF) continue;
        tot++;
        sum += dists[i][j];
      }
    }
    double ans = (double)sum / tot;
    cout << "Case " << tc << ": average length between pages = " << fixed << setprecision(3) << ans << " clicks" << endl;
  }
	return 0;
}

