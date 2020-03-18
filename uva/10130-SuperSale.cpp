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
vector<ii> a;
int solve(int n, int w) {
	if (dp[n][w] == -1) {
		if (w == 0 or n == 0) dp[n][w] = 0;
		else if (a[n].second > w) dp[n][w] = solve(n - 1, w);
		else dp[n][w] = max(solve(n - 1, w), solve(n - 1, w - a[n].second) + a[n].first);
	}
	return dp[n][w];
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		int n;
		cin >> n;
		a.resize(n + 1);
		loop(n) cin >> a[i + 1].first >> a[i + 1].second;
		int g;
		cin >> g;
		vi mw(g);
		int ans = 0, w = 0;
		loop(g) {
			cin >> mw[i];
			w = max(w, mw[i]);
		}
		dp.assign(n + 1, vi(w + 1, -1));
		loop(g) ans += solve(n, mw[i]);
		cout << ans << endl;
	}
	return 0;
}

