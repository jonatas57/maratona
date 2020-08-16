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

ll dp[201][201][201], ss[3][211];

ll solve(int r, int g, int b) {
	if (r < 0 or b < 0 or g < 0) return -INFLL;
	if (dp[r][g][b] == -1) {
		int x = (r == 0) + (g == 0) + (b == 0);
		if (x >= 2) dp[r][g][b] = 0;
		else {
			if (r and g) dp[r][g][b] = max(dp[r][g][b], ss[0][r] * ss[1][g] + solve(r - 1, g - 1, b));
			if (r and b) dp[r][g][b] = max(dp[r][g][b], ss[0][r] * ss[2][b] + solve(r - 1, g, b - 1));
			if (g and b) dp[r][g][b] = max(dp[r][g][b], ss[1][g] * ss[2][b] + solve(r, g - 1, b - 1));
		}
	}
	return dp[r][g][b];
}
int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	vi sz(3);
	loop(3) cin >> sz[i];
	memset(&dp, -1, sizeof dp);
	loop(3) {
		vloop(j, sz[i]) cin >> ss[i][j + 1];
		ss[i][0] = -1;
		sort(ss[i], ss[i] + sz[i] + 1);
	}
	cout << solve(sz[0], sz[1], sz[2]) << endl;
	return 0;
}

