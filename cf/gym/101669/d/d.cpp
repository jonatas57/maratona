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
  vector<ii> adj;
  graph(int n) : size(n) {}
  void addEdge(int a, int b) {
    adj.emplace_back(a, b);
  }
};

struct dsu {
  vi id, sz;

  dsu(int n) : id(n), sz(n, 1) {
    loop(n) id[i] = i;
  }

  int find(int x) {
    return x == id[x] ? x : id[x] = find(id[x]);
  }

  bool join(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (sz[a] > sz[b]) swap(a, b);
    id[a] = id[b];
    sz[b] += sz[a];
    return true;
  }
};

int kruskall(graph& g) {
  int ans = 0;
  dsu uf(g.size);
  for (auto& [u, v] : g.adj) {
    ans += uf.join(u, v);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n, m;
  cin >> m >> n;
  graph g(m);
  vi row(n, -1);
  loop(m) {
    int k;
    cin >> k;
    vloop(j, k) {
      int x;
      cin >> x;
      x--;
      if (row[x] == -1) row[x] = i;
      else g.addEdge(i, row[x]), row[x] = -1;
    }
  }
  cout << kruskall(g) << endl;
  return 0;
}

