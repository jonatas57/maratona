#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef vector<int>        vi;
typedef vector<bool>       vb;
typedef pair<int, int>     ii;

const int INF = 0x3f3f3f3f;
const ll  INFLL = 0x3f3f3f3f3f3f3f3fll;

#define each(x, s)  for(auto& x : s)
#define loop(x)     for(int i = 0;i < x;i++)
#define vloop(v, x) for(int v = 0;v < x;v++)
#define iter(a)     a.begin(), a.end()
#define riter(a)    a.rbegin(), a.rend()
#define endl        "\n"
#define avg(l, r)   (l + r) / 2

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

  int t;
  cin >> t;
  loop(t) {
    int n;
    cin >> n;
    vi p(n);
    dsu uf(n);
    loop(n) {
      cin >> p[i];
      uf.join(i, p[i] - 1);
    }
    int ans = 0;
    vector<vi> pos(n);
    loop(n) {
      pos[uf.find(i)].push_back(i);
    }
    each(v, pos) {
      for (int i = 0;i < (int)v.size() - 1;i++) {
        ans = gcd(ans, v[i + 1] - v[i]);
      }
    }
    cout << ans << endl;
  }
  return 0;
}

