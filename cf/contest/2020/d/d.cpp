#include <bits/stdc++.h>

using namespace std;

typedef long long      ll;
typedef vector<int>    vi;
typedef vector<bool>   vb;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll  INFLL = 0x3f3f3f3f3f3f3f3fll;

#define each(x, s)  for (auto& x : s)
#define loop(x)     for (int i = 0;i < x;i++)
#define vloop(v, x) for (int v = 0;v < x;v++)
#define iter(a)     a.begin(), a.end()
#define riter(a)    a.rbegin(), a.rend()
#define endl        "\n"

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
    int n, m;
    cin >> n >> m;
    int gs = n;
    dsu uf(n);
    vector<map<int, vector<ii>>> ms(11);
    loop(m) {
      int a, d, k;
      cin >> a >> d >> k;
      if (!k) continue;
      a--;
      ms[d][a % d].emplace_back(a, k);
    }
    for (int i = 1;i <= 10;i++) {
      for (auto& [mod, ops] : ms[i]) {
        sort(iter(ops));
        int last = -1;
        for (auto& [a, k] : ops) {
          for (int x = max(a, last);x < a + k * i;x += i) {
            gs -= uf.join(x, x + i);
          }
          last = a + k * i;
        }
      }
    }
    cout << gs << endl;
  }
  return 0;
}

