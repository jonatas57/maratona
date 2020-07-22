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
vi v(4000);

bool solve(int at, int x) {
	if (x < 0) return false;
	if (dp[at][x] == -1) {
		if (v[at] == x) dp[at][x] = 1;
		else if (at == 0) dp[at][x] = 0;
		else dp[at][x] = solve(at - 1, x) || solve(at - 1, x - v[at]);
	}
	return dp[at][x];
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		int n;
		cin >> n;
		vi a(n + n), m(n + n);
		loop(n + n) cin >> a[i];
		m[0] = 0;
		for (int i = 1;i < n + n;i++) m[i] = a[m[i - 1]] < a[i] ? i : m[i - 1];
		int at = 0;
		for (int i = n + n;i;i = m[i - 1], at++) {
			v[at] = i - m[i - 1];
		}
		dp.assign(at, vi(n + n + 1, -1));
		cout << (solve(at - 1, n) ? "YES" : "NO") << endl;
	}
	return 0;
}

