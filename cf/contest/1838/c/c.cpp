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
    int n, m;
    cin >> n >> m;
    bool transpose = false;
    if (n == 4) {
      swap(n, m);
      transpose = true;
    }
    vector<vi> a(n, vi(m));
    for (int i = 0, val = 1;~i & 1 or i < n;i += 2) {
      if (i >= n) i = 1;
      for (int j = 0;j < m;j++, val++) {
        a[i][j] = val;
      }
    }
    if (transpose) {
      vector<vi> b(m, vi(n));
      loop(m) vloop(j, n) b[i][j] = a[j][i];
      a.swap(b);
    }
    each(v, a) {
      each(x, v) cout << x << " ";
      cout << endl;
    }
  }
  return 0;
}

