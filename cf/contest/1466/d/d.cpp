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
  vi deg;
  vector<ll> w;
  graph(int n) : size(n), adj(n), deg(n, 0), w(n) {}
  void addEdge(int a, int b) {
    adj[a].push_back(b);
    adj[b].push_back(a);
    deg[a]++;
    deg[b]++;
  }
};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n;
    cin >> n;
    graph g(n);
    ll sum = 0;
    loop(n) {
      cin >> g.w[i];
      sum += g.w[i];
    }
    int u, v;
    loop(n - 1) {
      cin >> u >> v;
      g.addEdge(u - 1, v - 1);
    }
    priority_queue<pair<ll, int>> q;
    loop(n) q.emplace(g.w[i], g.deg[i]);
    cout << sum << " ";
    for (int k = 2;k < n;k++) {
      ll w;
      int d;
      do {
        tie(w, d) = q.top();
        q.pop();
      } while (!q.empty() and d == 1);
      sum += w;
      d--;
      cout << sum << " ";
      q.emplace(w, d);
    }
    cout << endl;
  }
  return 0;
}

