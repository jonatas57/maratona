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
#define avg(l, r)          (l + r) >> 1
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

const ll mod = 1000000007;
const double EPS = 1e-7;
const double PI = acos(-1);

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n, m, k;
  cin >> n >> m >> k;
  int lim = 2 * (2 * n * m - m - n);
  if (k > lim) cout << "NO" << endl;
  else {
    vector<pair<int, string>> ans;
    auto add = [&](int q, string s) {
      q = min(q, k);
      if (!q) return;
      ans.emplace_back(q, s);
      k -= q;
    };
    add(m - 1, "R");
    for (int i = 0;i < m - 1 and k;i++) {
      add(n - 1, "D");
      add(n - 1, "U");
      add(1, "L");
    }
    for (int i = 0;i < n - 1 and k;i++) {
      add(1, "D");
      add(m - 1, "R");
      add(m - 1, "L");
    }
    add(n - 1, "U");
    cout << "YES" << endl << ans.size() << endl;
    for (auto& [q, s] : ans) cout << q << " " << s << endl;
  }
  return 0;
}

