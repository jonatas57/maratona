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

vector<ll> dp(1e5 + 1, -1);

ll fat(ll x) {
	if (dp[x] == -1) {
		if (x == 0) dp[x] = 1;
		else dp[x] = x * fat(x - 1) % mod;
	}
	return dp[x];
}

tuple<ll, ll, ll> eucl(ll a, ll b) {
	if (b == 0) return {1, 0, a};
	ll x, y, g;
	tie(x, y, g) = eucl(b, a % b);
	return make_tuple(y, x - a / b * y, g);
}

ll inv(ll a, ll mod) {
	ll n, m, g;
	tie(n, m, g) = eucl(a, mod);
	return (n % mod + mod) % mod;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	ll n;
	string s;
	cin >> n >> s;
	map<char, int> cnt;
	each(c, s) cnt[c]++;
	ll ans = fat(n);
	each(p, cnt) {
		ans *= inv(fat(p.second), mod);
	}
	map<char, int> last;
	bool p = false;
	int sz = 0;
	loop(n) {
		if (last[s[i]]) {

	cout << n * ans % mod << endl;
	return 0;
}

