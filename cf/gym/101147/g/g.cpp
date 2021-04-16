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
const double EPS = 1e-7;
const double PI = acos(-1);

vector<vector<ll>> dp;

ll solve(int n, int k) {
  if (dp[n][k] == -1) {
    if (k > n or k == 0 or n == 0) dp[n][k] = 0;
    else if (n == 1) dp[n][k] = 1;
    else dp[n][k] = k * (solve(n - 1, k) + solve(n - 1, k - 1)) % mod;
  }
  return dp[n][k];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  freopen("galactic.in", "r", stdin);

  vector<ll> fat(1001, 1);
  loop(1000) fat[i + 1] = fat[i] * (i + 1) % mod;

  int t;
  cin >> t;
  loop(t) {
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    if (k <= n) {
      dp.assign(n + 1, vector<ll>(k + 1, -1));
      ans = solve(n, k);
    }
    cout << ans << endl;
  }
  return 0;
}

