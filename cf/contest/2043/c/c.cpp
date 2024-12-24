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

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  
  int t;
  cin >> t;
  loop(t) {
    int n;
    cin >> n;
    vi a(n);
    int p = -1;
    loop(n) {
      cin >> a[i];
      if (abs(a[i]) != 1) p = i;
    }
    set<int> s;
    s.insert(0);
    auto solve = [&] (int st, int en, int d) {
      int l = 0, r = 0, sum = 0, x = 0, y = 0;
      for (int i = st;i != en;i += d) {
        sum += a[i];
        if (sum > l) y = max(y, sum - l);
        if (sum < r) x = min(x, sum - r);
        l = min(sum, l);
        r = max(sum, r);
      }
      vi b(y - x + 1);
      iota(iter(b), x);
      s.insert(iter(b));
    };
    if (p == -1) solve(0, n, 1);
    else {
      if (p) solve(0, p, 1);
      if (p < n - 1) solve(p + 1, n, 1);
      int l1 = 0, r1 = 0, l2 = 0, r2 = 0, sum = 0;
      for (int i = p - 1;i >= 0;i--) {
        sum += a[i];
        l1 = min(sum, l1);
        r1 = max(sum, r1);
      }
      sum = 0;
      for (int i = p + 1;i < n;i++) {
        sum += a[i];
        l2 = min(sum, l2);
        r2 = max(sum, r2);
      }
      for (int i = l1 + l2;i <= r1 + r2;i++) s.insert(a[p] + i);
    }
    cout << s.size() << endl;
    each(x, s) cout << x << " ";
    cout << endl;
  }
  return 0;
}

