#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>         vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define each(x, s)         for(auto& x : s)
#define ceach(x, s)        for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i+=z)
#define loop(x)             for(int i = 0;i < x;i++)
#define pb                 push_back

#define N                  100000
struct edge {
  int src, trg;
  edge(int s, int t) : src(s), trg(t) {}
  operator tuple<int&, int&>() {
    return {src, trg};
  }
};
int n, m;
vector<edge> es;
map<int, mii> adj;

int par[N], sz[N];
void makeset(int n) {
  loop(n) {
    par[i] = i;
    sz[i] = 1;
  }
}
int find(int x) {
  if (x == par[x]) return par[x];
  else return par[x] = find(par[x]);
}
void join(int x, int y) {
  int a = find(x), b = find(y);
  if (a == b) return;
  if (sz[a] > sz[b]) swap(a, b);
  par[a] = b;
  sz[b] += sz[a];
}
int components() {
  vb visit(n + 1, false);
  queue<int> q;
  int comp = 0;
  rep(1, n + 1, 1) {
    if (!visit[i]) {
      comp++;
      visit[i] = true;
      q.push(i);
      while (!q.empty()) {
        int x = q.front();q.pop();
        each(p, adj[x]) {
          int v = p.first;
          if (!visit[v] and p.second) {
            visit[v] = true;
            q.push(v);
          }
        }
      }
    }
  }
  return comp;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

  cin >> n >> m;
  int s, t;
  loop(m) {
    cin >> s >> t;
    es.emplace_back(s, t);
    adj[s][t]++;
    adj[t][s]++;
  }
  int q, a, b, com;
  cin >> q;
  vi del(q);
  loop(q) {
    cin >> del[i];
    tie(a, b) = es[del[i] - 1];

    adj[a][b]--;
    adj[b][a]--;
  }
  com = components();
  list<int> ans;
  ans.push_front(com);
  makeset(n);
  each(p, adj) {
    int u = p.first;
    each(q, p.second) {
      if (q.second) {
        join(u, q.first);
      }
    }
  }
  for (int i = q - 1;i > 0;i--) {
    tie(a, b) = es[del[i] - 1];
    if (find(a) != find(b)) {
      join(a, b);
      com--;
    }
    ans.push_front(com);
  }
  each(i, ans) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
//268836JY
