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

  int t;
  cin >> t;
  ll maxv = INT_MAX;
  loop(t) {
    string s;
    cin >> s;
    int n = s.length();
    vector<ll> dp(n + 1, 0);
    for (int i = 1;i <= n;i++) {
      ll x = 0;
      for (ll j = 0, b = 1;i > j and j <= 10;j++, b *= 10) {
        x += b * (s[i - j - 1] - '0');
        if (x == 0 and j) continue;
        if (x > maxv) break;
        dp[i] = max(dp[i], dp[i - j - 1] + x);
      }
    }
    cout << dp[n] << endl;
  }
	return 0;
}

