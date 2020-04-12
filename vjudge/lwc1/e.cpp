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

int dp[21][21][1001][2];
int cost[21][21], val[21][21];
int bcost[21];

int N, M, K;

int solve(int n, int m, int k, int ok = 0) {
	if (k < 0) return -INF;
	if (dp[n][m][k][ok] == -1) {
		if (n == 0 or k == 0) dp[n][m][k][ok] = 0;
		else if (m == 0) dp[n][m][k][ok] = solve(n - 1, M, k, 0);
		else {
			int bc = !ok * bcost[n];
			dp[n][m][k][ok] = max(solve(n, m - 1, k, ok), 
													  solve(n, m    , k - cost[n][m] - bc, ok | 1) + val[n][m]);
		}
	}
	return dp[n][m][k][ok];
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		cin >> N >> M >> K;
		for (int i = 1;i <= N;i++) cin >> bcost[i];
		for (int i = 1;i <= N;i++) {
			for (int j = 1;j <= M;j++) {
				cin >> cost[i][j];
			}
		}
		for (int i = 1;i <= N;i++) for (int j = 1;j <= M;j++) cin >> val[i][j];
		memset(dp, -1, sizeof(dp));
		if (dp[2][2][2][1] != -1) return 0;
		cout << solve(N, M, K) << endl;
	}
	return 0;
}

