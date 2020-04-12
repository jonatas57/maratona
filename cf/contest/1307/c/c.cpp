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

	string s;
	cin >> s;
	ll ans = 0;
	vector<ll> cnt(26, 0);
	vector<vector<ll>> dp(26, vector<ll>(26, 0));
	each(c, s) {
		loop(26) {
			dp[i][c - 'a'] += cnt[i];
			ans = max(ans, dp[i][c - 'a']);
		}
		cnt[c - 'a']++;
		ans = max(ans, cnt[c - 'a']);
	}
	cout << ans << endl;
	return 0;
}
