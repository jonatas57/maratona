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
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

int n;

ll xp(ll b, ll e) {
	if (e == 1) return b;
	ll c = xp(b, e / 2);
	c *= c;
	c %= MOD;
	if (e & 1) c *= b, c %= MOD;
	return c;
}

ll solve(string s, int p) {
	if (p == n - 1) return s[p] - '0';
	ll ans = (s[p] == '0' ? 0 : xp(xp(2, n - p - 1), 2));
	return (ans + 2 * solve(s, p + 1)) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	string x;
	cin >> x;
	n = x.length();
	cout << solve(x, 0) << endl;
	return 0;
}
