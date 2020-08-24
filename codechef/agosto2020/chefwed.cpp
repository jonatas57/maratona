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

vi dp, a;
vector<vi> acc;
set<int> fs;
int k;

int argu(int r, int l = 0) {
	int x = 0, y;
	each(f, fs) {
		if ((y = acc[r][f] - acc[l][f]) >= 2) x += y;
	}
	return x;
}

int solve(int at) {
	if (dp[at] == INF) {
		if (at == 0) dp[at] = 0;
		else {
			dp[at] = k + argu(at);
			loop(at) {
				dp[at] = min(dp[at], k + argu(at, i) + solve(i));
			}
		}
	}
	return dp[at];
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		int n;
		cin >> n >> k;

		a.resize(n);
		acc.assign(1, vi(101, 0));
		fs.clear();

		loop(n) {
			cin >> a[i];
			fs.insert(a[i]);
			acc.push_back(acc.back());
			acc[i + 1][a[i]]++;
		}
		dp.assign(n + 1, INF);
		cout << solve(n) << endl;
	}
	return 0;
}

