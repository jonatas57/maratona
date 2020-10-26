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

vector<vector<ll>> dp;
vi a;

ll solve(int neg, int n) {
  if (dp[neg][n] == -1) {
    if (n == 0) dp[neg][n] = neg ? 0 : -INF;
    else dp[neg][n] = max({solve(neg, n - 1), solve(!neg, n - 1) + a[n - 1] * (neg ? -1 : 1)});
  }
  return dp[neg][n];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    int n, q;
    cin >> n >> q;
    a.resize(n);
    loop(n) cin >> a[i];
    dp.assign(2, vector<ll>(n + 1, -1));
    cout << max(solve(0, n), solve(1, n)) << endl;
  }
  return 0;
}

