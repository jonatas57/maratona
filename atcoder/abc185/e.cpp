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

vi a, b;
vector<vi> dp(1001, vi(1001, INF));

int solve(int n, int m) {
  if (dp[n][m] == INF) {
    if (n == 0) dp[n][m] = m;
    else if (m == 0) dp[n][m] = n;
    else if (a[n - 1] == b[m - 1]) dp[n][m] = solve(n - 1, m - 1);
    else dp[n][m] = 1 + min({solve(n, m - 1), solve(n - 1, m), solve(n - 1, m - 1)});
  }
  return dp[n][m];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n, m;
  cin >> n >> m;
  a.resize(n);
  b.resize(m);
  loop(n) cin >> a[i];
  loop(m) cin >> b[i];
  cout << solve(n, m) << endl;
  return 0;
}

