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
  vector<list<ii>> adj;
  void init(int n) {
    size = n;
    adj.resize(n);
  }
  void addEdge(int a, int b, int w) {
    adj[a].emplace_back(b, w);
    adj[b].emplace_back(a, w);
  }
} g;

vector<vi> dist(250000, vi(11, -1));

int solve(int n, int k) {
  if (dist[n][k] == -1) {
    if (k == 0) dist[n][k] = 0;
    else {
      dist[n][k] = INF;
      for (auto& [v, w] : g.adj[n]) {
        for (int i = k - 1;i >= 0;i -= 2) {
          dist[n][k] = min(dist[n][k], solve(v, i) + w * (k - i));
        }
      }
    }
  }
  return dist[n][k];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n, m, k;
  cin >> n >> m >> k;
  vector<vi> ans(n, vi(m, -1));
  if (~k & 1) {
    g.init(n * m);
    loop(n) vloop(j, m - 1) {
      int x;
      cin >> x;
      g.addEdge(i * m + j, i * m + j + 1, x);
    }
    loop(n - 1) vloop(j, m) {
      int x;
      cin >> x;
      g.addEdge(i * m + j, (i + 1) * m + j, x);
    }
    loop(n) vloop(j, m) ans[i][j] = 2 * solve(i * m + j, k >> 1);
  }
  each(v, ans) {
    each(x, v) cout << x << " ";
    cout << endl;
  }
  return 0;
}

