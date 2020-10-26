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

ii getcoord(int x) {
  x--;
  int n = (-1 + sqrt(1 + 8 * x)) / 2;
  return {n, x - n * (n + 1) / 2};
}

bool ok(ii a, ii b) {
  return a.first == b.first or a.second == b.second or b.first - a.first == b.second - a.second;
}

int dist(ii a, ii b) {
  return max(abs(a.first - b.first), abs(a.second - b.second));
}

struct graph {
  int size;
  vector<list<ii>> adj;
  int mask;
  graph(int n) : size(n), adj(n), mask((1 << n) - 1) {}
  void addEdge(int a, int b, int w) {
    adj[a].emplace_back(b, w);
    adj[b].emplace_back(a, w);
  }
};

bool cycle(graph& g, int u = 0, int mask = 1, int dist = -1) {
  if (mask == g.mask) {
    each(p, g.adj[u]) {
      if (p.first == 0 and p.second == dist) return true;
    }
    return false;
  }
  each(p, g.adj[u]) {
    if (mask & (1 << p.first)) continue;
    if (dist == -1) dist = p.second;
    if (dist != p.second) continue;
    if (cycle(g, p.first, mask | (1 << p.first), dist)) return true;
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  string s;
  while (getline(cin, s)) {
    stringstream ss;
    ss << s;
    vector<ii> a;
    set<int> ps;
    int x, sz = 0;
    while (ss >> x) {
      a.push_back(getcoord(x));
      ps.insert(x);
      sz++;
    }
    if (!sz) continue;
    graph g(sz);
    loop(sz) {
      vloop(j, i) {
        if (ok(a[i], a[j])) g.addEdge(i, j, dist(a[i], a[j]));
      }
    }
    if (sz <= 2 or sz == 5 or !cycle(g)) cout << s << " are not the vertices of an acceptable figure" << endl;
    else cout << s << " are the vertices of a " << (sz == 3 ? "triangle" : sz == 4 ? "parallelogram" : "hexagon") << endl;
  }
  return 0;
}

