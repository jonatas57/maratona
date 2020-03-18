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

vector<vi> dp;
int n, total;
vi a;

int solve(int pos, int sum) {
	if (pos == n) return abs(2 * sum - total);
	if (dp[pos][sum] == INF) dp[pos][sum] = min(solve(pos + 1, sum), solve(pos + 1, sum + a[pos]));
	return dp[pos][sum];
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		cin >> n;
		total = 0;
		a.resize(n);
		loop(n) {
			cin >> a[i];
			total += a[i];
		}
		dp.assign(n, vi(total + 1, INF));
		cout << solve(0, 0) << endl;
	}
	return 0;
}

