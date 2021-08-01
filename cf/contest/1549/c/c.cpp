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
  vector<set<int>> adj;
  vb vul;
  int cnt;
  graph(int n) : size(n), adj(n), vul(n, false), cnt(0) {}
  void addEdge(int a, int b) {
    if (a > b) swap(a, b);
    adj[a].insert(b);
    if (!vul[a]) vul[a] = true, cnt++;
  }
  void remEdge(int a, int b) {
    if (a > b) swap(a, b);
    adj[a].erase(b);
    if (vul[a] and adj[a].empty()) vul[a] = false, cnt--;
  }
  int killVul() {
    return cnt;
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
  int q;
  cin >> q;
  loop(q) {
    int op;
    cin >> op;
    if (op == 3) {
      cout << n - g.killVul() << endl;
    }
    else {
      int u, v;
      cin >> u >> v;
      u--, v--;
      if (op == 1) {
        g.addEdge(u, v);
      }
      else {
        g.remEdge(u, v);
      }
    }
  }
  return 0;
}

