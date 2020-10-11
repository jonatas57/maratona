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

int n, k;
string s;
vi dp;

int solve(int n) {
  if (n == -1) return -1;
  if (dp[n] == -1) {
    dp[n] = solve(n - 1) + 1;
    bool alt = true;
    for (int i = n - 1;i >= 0 and i > n - k;i--) {
      if (s[i] == s[i + 1]) alt = false;
      if (!alt) dp[n] = min(dp[n], solve(i - 1) + 1);
    }
  }
  return dp[n];
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    cin >> n >> k >> s;
    dp.assign(n, -1);
    cout << solve(n - 1) << endl;
  }
  return 0;
}

