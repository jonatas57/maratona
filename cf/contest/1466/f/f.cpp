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

ll xp(ll b, ll e) {
  if (e == 0) return 1;
  ll c = xp(b, e >> 1);
  c = c * c % mod;
  if (e & 1) c = c * b % mod;
  return c;
}

vi kruskall(graph& g) {
  vi ans;
  dsu uf(g.size);
  int i = 0;
  for (auto& [u, v] : g.adj) {
    if (uf.join(u, v)) {
      ans.push_back(i);
    }
    i++;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n, m;
  cin >> n >> m;
  graph g(m + 1);
  loop(n) {
    int p, u, v;
    cin >> p >> u;
    if (p == 2) cin >> v, v--;
    else v = m;
    u--;
    g.addEdge(u, v);
  }
  vi mst = kruskall(g);
  int ans = mst.size();
  cout << xp(2, ans) << " " << ans << endl;
  each(x, mst) cout << x + 1 << " ";
  cout << endl;
  return 0;
}

