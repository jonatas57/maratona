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
    vb used(n, false);
    vi ans(n);
    if (n & 1) {
      ans[n - 1] = n;
      ans[n - 2] = n - 1;
      ans[n - 3] = 3;
      ans[n - 4] = 1;
      loop(4) used[ans[n - i - 1] - 1] = true;
    }
    else if (n == 6) {
      ans = {1, 2, 4, 6, 5, 3};
    }
    else {
      int msb = 1;
      while (msb <= n) msb <<= 1;
      msb >>= 1;
      ans[n - 1] = msb;
      ans[n - 2] = msb - 1;
      ans[n - 3] = msb - 2;
      ans[n - 4] = 3;
      ans[n - 5] = 1;
      loop(5) used[ans[n - i - 1] - 1] = true;
    }
    int p = 0;
    loop(n) {
      if (ans[i]) continue;
      while (used[p]) p++;
      used[p] = true;
      ans[i] = p + 1;
    }
    int k = 0;
    for (int i = 0;i < n;i++) {
      if (i & 1) k |= ans[i];
      else k &= ans[i];
    }
    cout << k << endl;
    each(x, ans) cout << x << " ";
    cout << endl;
  }
  return 0;
}

