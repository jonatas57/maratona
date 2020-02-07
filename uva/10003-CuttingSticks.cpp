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
vector<vi> memo;

int solve(int l, int r) {
	if (memo[l][r] == -1) {
		if (l + 1 == r) memo[l][r] = 0;
		else {
			int ans = INF;
			for (int i = l + 1;i < r;i++) {
				ans = min(ans, solve(l, i) + solve(i, r));
			}
			memo[l][r] = ans + a[r] - a[l];
		}
	}
	return memo[l][r];
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int l;
	while (cin >> l and l) {
		int n;
		cin >> n;
		a.resize(n + 2);
		loop(n) cin >> a[i + 1];
		a[0] = 0;
		a[n + 1] = l;
		memo.assign(n + 2, vi(n + 2, -1));
		cout << "The minimum cutting is " << solve(0, n + 1) << "." << endl;
	}
	return 0;
}

