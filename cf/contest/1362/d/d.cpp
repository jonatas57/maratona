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
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n, m;
  cin >> n >> m;
  graph g(n);
  loop(m) {
    int u, v;
    cin >> u >> v;
    g.addEdge(u - 1, v - 1);
  }
  vector<ii> t(n);
  loop(n) {
    cin >> t[i].first;
    t[i].second = i;
  }
  vi ans, mw(n, 0);
  vb written(n, false);
  sort(iter(t));
  for (auto& [topic, id] : t) {
    if (mw[id] != topic - 1) {
      ans.clear();
      break;
    }
    ans.push_back(id + 1);
    written[id] = true;
    each(v, g.adj[id]) {
      if (written[v]) continue;
      if (mw[v] < topic - 1) {
        ans.clear();
        break;
      }
      else mw[v] = topic;
    }
    if (ans.empty()) break;
  }
  if (ans.empty()) {
    cout << -1 << endl;
  }
  else {
    each(x, ans) cout << x << " ";
    cout << endl;
  }
  return 0;
}

