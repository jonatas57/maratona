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

vi dp(10e7 + 1, -1);

ll collatzLen(ll x, bool first = true) {
	if (x <= 1e7 and dp[x] != -1) return dp[x];
	ll y = x == 1 and ! first ? 0 : 1 + collatzLen(x & 1 ? 3 * x + 1 : x >> 1, false);
	if (x <= 1e7) return dp[x] = y;
	return y;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int x, y;
	while (cin >> x >> y and x | y) {
		if (x > y) swap(x, y);
		int max = 0, ans = x;
		for (int i = x;i <= y;i++) {
			int c = collatzLen(i);
			if (max < c) {
				max = c;
				ans = i;
			}
		}
		cout << "Between " << x << " and " << y << ", " << ans << " generates the longest sequence of " << max << " values." << endl;
	}
	return 0;
}

