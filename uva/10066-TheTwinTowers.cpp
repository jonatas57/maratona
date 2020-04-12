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

vi a, b;
vector<vi> dp;
int lcs(int n, int m) {
	if (dp[n][m] == -1) {
		if (!n or !m) dp[n][m] = 0;
		else if (a[n - 1] == b[m - 1]) dp[n][m] = lcs(n - 1, m - 1) + 1;
		else dp[n][m] = max(lcs(n - 1, m), lcs(n, m - 1));
	}
	return dp[n][m];
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, m;
	for (int i = 1;cin >> n >> m and n | m;i++) {
		a.resize(n), b.resize(m);
		loop(n) cin >> a[i];
		loop(m) cin >> b[i];
		dp.assign(n + 1, vi(m + 1, -1));
		cout << "Twin Towers #" << i << endl;
		cout << "Number of Tiles : " << lcs(n, m) << endl << endl;
	}
	return 0;
}

