#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define INFLL              0x3f3f3f3f3f3f3f3f
#define each(x, s)         for(auto& x : s)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

const ll mod = 1000000007;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n;
  for (int tc = 1;cin >> n and n;tc++) {
    string s;
    vi a(n);
    loop(n) cin >> s >> a[i];
    vb used(n, false);
    int k = -1;
    int ans = 0;
    while (true) {
      vi dp(n, 0), par(n, -1), lasts;
      int k2 = 0;
      loop(n) {
        if (used[i]) continue;
        vloop(j, i) {
          if (a[i] <= a[j] or used[j]) continue;
          if (dp[i] < dp[j]) {
            dp[i] = dp[j];
            par[i] = j;
          }
        }
        dp[i]++;
        if (dp[i] > k2) {
          k2 = dp[i];
          lasts.clear();
          lasts.push_back(i);
        }
        else if (dp[i] == k2) {
          lasts.push_back(i);
        }
      }
      if (k == -1) k = k2;
      if (k2 < k) break;
      for (int x : lasts) {
        bool ok = true;
        int y = x;
        while (y != -1) {
          if (used[y]) ok = false;
          y = par[y];
        }
        if (ok) {
          ans += k;
          while (x != -1) {
            used[x] = true;
            x = par[x];
          }
        }
        else break;
      }
    }
    cout << "Case #" << tc << ": " << ans << endl;
  }
	return 0;
}

