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

vector<vector<ii>> dp;
vi a;
int m;

ii solve(int n, int sum) {
	if (dp[n][sum].first == -1) {
		if (n == 0) dp[n][sum] = {sum == 0, 0};
		else {
			dp[n][sum] = solve(n - 1, sum);
			auto y = solve(n - 1, (sum + m - a[n - 1]) % m);
			dp[n][sum].first |= y.first;
			dp[n][sum].second |= y.first;
		}
	}
	return dp[n][sum];
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n >> m;
	a.resize(n);
	loop(n) cin >> a[i], a[i] %= m;
	bool p = true;
	if (n <= m) {
		dp.resize(n + 1, vector<ii>(m, {-1, -1}));
		auto x = solve(n, 0);
		p = x.first and x.second;
	}
	cout << (p ? "YES" : "NO") << endl;
	return 0;
}

