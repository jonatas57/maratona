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

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n, m;
  cin >> n >> m;
  dsu uf(n);
  vi a(n), b(n);
  int sz = n;
  loop(n) cin >> a[i];
  loop(n) cin >> b[i];
  loop(m) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    sz -= uf.join(u, v);
  }
  vector<ll> suma(n, 0), sumb(n, 0);
  loop(n) {
    suma[uf.find(i)] += a[i];
    sumb[uf.find(i)] += b[i];
  }
  bool ok = true;
  for (int i = 0;i < n and ok;i++) {
    if (suma[i] != sumb[i]) ok = false;
  }
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}

