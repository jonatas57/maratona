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

int f(int odd, int n, bool mx = true) {
  if (n == 0) return 0;
  if (n == 1) return 0;
  if (mx) {
    if (odd >= 2) return f(odd - 2, n - 1, !mx);
    if (n > odd + 1) return f(odd, n - 1, !mx);
    return f(0, n - 1, !mx) + 1;
  }
  if (!odd) return f(odd, n - 1, !mx);
  return f(odd - 1, n - 1, !mx) + 1;
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n;
    cin >> n;
    vi a(n);
    loop(n) cin >> a[i];
    ll s = 0;
    int o = 0;
    loop(n) {
      if (a[i] & 1) o++;
      s += a[i];
      int p = i / 2;
      int q = o / 3;
      int r = o % 3;
      int x = min(p, q);
      r += (q - x) * 3;
      if (r == 1 and i) {
        x++;
      }
      cout << s - x << " ";
    }
    cout << endl;
  }
  return 0;
}

