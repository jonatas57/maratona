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

struct segtree {
  int size;
  vector<ii> st;
  vi lazy;

  segtree(int n) : size(n), st(4 * n + 10), lazy(4 * n + 10) {
    build(1, 0, size - 1);
  }

  void build(int id, int l, int r) {
    if (l == r) st[id] = {0, -l};
    else {
      int mid = avg(l, r);
      build(id << 1, l, mid);
      build(id << 1 | 1, mid + 1, r);
      st[id] = min(st[id << 1], st[id << 1 | 1]);
    }
  }

  void prop(int id, int l, int r) {
    if (lazy[id]) {
      st[id].first += lazy[id];
      if (l != r) {
        lazy[id << 1] += lazy[id];
        lazy[id << 1 | 1] += lazy[id];
      }
      lazy[id] = 0;
    }
  }

  void update(int id, int l, int r, int a, int b, int val) {
    prop(id, l, r);
    if (l > b or r < a) return;
    if (a <= l and r <= b) {
      lazy[id] = val;
      prop(id, l, r);
    }
    else {
      int mid = avg(l, r);
      update(id << 1, l, mid, a, b, val);
      update(id << 1 | 1, mid + 1, r, a, b, val);
      st[id] = min(st[id << 1], st[id << 1 | 1]);
    }
  }

  ii query(int id, int l, int r, int a, int b) {
    prop(id, l, r);
    if (l > b or r < a) return {INF, INF};
    if (a <= l and r <= b) return st[id];
    int mid = avg(l, r);
    return min(query(id << 1, l, mid, a, b), query(id << 1 | 1, mid + 1, r, a, b));
  }
  void update(int l, int r, int val) {
    update(1, 0, size - 1, l, r, val);
  }
  ii query(int l, int r) {
    return query(1, 0, size - 1, l, r);
  }
};

struct graph {
  int size;
  vector<list<int>> adj;
  graph(int n) : size(n), adj(n) {}
  void addEdge(int a, int b) {
    adj[a].push_back(b);
  }
};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n, m;
    cin >> n >> m;
    segtree st(n);
    loop(n) st.update(i, i, i);
    graph g(n);
    int a, b;
    loop(m) {
      cin >> a >> b;
      g.addEdge(a - 1, b - 1);
      st.update(b - 1, b - 1, -1);
    }
    vi ans;
    int qtd = n;
    while (qtd) {
      auto [d, u] = st.query(0, n - 1);
      u = abs(u);
      ans.push_back(u + 1);
      each(v, g.adj[u]) {
        st.update(v, v, 1);
      }
      st.update(u + 1, n - 1, -1);
      st.update(u, u, INF);
      qtd--;
    }
    each(x, ans) cout << x << " ";
    cout << endl;
  }
  return 0;
}

