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

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n;
    cin >> n;
    vi a(n);
    map<int, vi> b;
    loop(n) {
      cin >> a[i];
      b[-a[i]].push_back(i);
    }
    vi l(n, -1), r(n, -1);
    loop(n - 1) {
      l[i + 1] = i;
      r[i] = i + 1;
    }
    int tot = n;
    auto join = [&] (int x, int y) {
      if (a[x] > a[y]) swap(x, y);
      if (l[x] == y) {
        l[x] = l[y];
        if (l[x] != -1) r[l[x]] = x;
        tot--;
      }
      else {
        r[x] = r[y];
        if (r[x] != -1) l[r[x]] = x;
        tot--;
      }
    };
    bool ok = b.size() == 1 - (b.begin()->first) and b[0].size() == 1;
    for (auto& [x, ps] : b) {
      if (x == 0) continue;
      int trg = tot - ps.size();
      each(p, b[x + 1]) {
        while (l[p] != -1 and a[l[p]] == -x) join(p, l[p]);
        while (r[p] != -1 and a[r[p]] == -x) join(p, r[p]);
      }
      if (tot != trg) ok = false;
    }
    cout << (ok ? "YES" : "NO") << endl;
  }
  return 0;
}

