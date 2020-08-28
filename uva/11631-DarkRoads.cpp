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

typedef tuple<int, int, int> tup;
struct graph {
  int size;
  vector<tup> es;
  graph(int n) : size(n) {}
  void addEdge(int a, int b, int w) {
    es.emplace_back(a, b, w);
  }
};

vi id, sz;
void init(int n) {
  id.resize(n);
  sz.resize(n);
  loop(n) {
    sz[i] = 1;
    id[i] = i;
  }
}
int find(int a) { return a == id[a] ? a : id[a] = find(id[a]); }
bool join(int a, int b) {
  a = find(a);
  b = find(b);
  if (a == b) return false;
  if (sz[a] > sz[b]) swap(a, b);
  id[a] = id[b];
  sz[b] += sz[a];
  return true;
}

int kruskall(graph& g) {
  int tot = 0;
  init(g.size);
  int a, b, w;
  sort(iter(g.es), [](tup a, tup b) { return get<2>(a) < get<2>(b); });
  each(e, g.es) {
    tie(a, b, w) = e;
    if (join(a, b)) tot += w;
  }
  return tot;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n, m;
  while (cin >> n >> m and n | m) {
    graph g(n);
    int a, b, w, tot = 0;
    loop(m) {
      cin >> a >> b >> w;
      g.addEdge(a, b, w);
      tot += w;
    }
    tot -= kruskall(g);
    cout << tot << endl;
  }
	return 0;
}

