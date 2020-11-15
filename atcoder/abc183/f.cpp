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

struct dsu {
  vector<mii> y;
  vi id, sz;

  dsu(int n) : y(n), id(n), sz(n, 1) {
    loop(n) {
      int c;
      cin >> c;
      y[i][c] = 1;
      id[i] = i;
    }
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
    for (auto& [k, v] : y[a]) {
      y[b][k] += v;
    }
    y[a].clear();
    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n, q;
  cin >> n >> q;
  dsu uf(n);
  int op, a, b;
  loop(q) {
    cin >> op >> a >> b;
    if (op == 1) uf.join(a - 1, b - 1);
    else cout << uf.y[uf.find(a - 1)][b] << endl;
  }
  return 0;
}

