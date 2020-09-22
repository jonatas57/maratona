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

vi a;
vector<vi> dp;

int solve(int at, int k) {
	if (at <= 0 or k == 0) return 0;
	if (dp[at][k] == -1) {
		int x = upper_bound(iter(a), a[at - 1] - 6) - a.begin();
		dp[at][k] = max(solve(at - 1, k), solve(x, k - 1) + at - x);
	}
	return dp[at][k];
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	a.resize(n);
	loop(n) cin >> a[i];
	sort(iter(a));
	dp.assign(n + 1, vi(k + 1, -1));
	cout << solve(n, k) << endl;
	return 0;
}

