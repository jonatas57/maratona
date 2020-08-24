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

ll xp(ll b, ll e) {
	if (e == 0) return 1;
	ll c = xp(b, e >> 1);
	c *= c;
	c %= mod;
	if (e & 1) c *= b, c %= mod;
	return c;
}

pair<ll, ll> eucl(ll a, ll b) {
	if (b == 0) return {1, 0};
	ll x, y;
	tie(x, y) = eucl(b, a % b);
	return {y, x - a / b * y};
}

ll inv(ll x) {
	if (x == 0) return 1;
	ll n = eucl(mod, x).second;
	return ((n % mod) + mod) % mod;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int k;
	string s;
	cin >> k >> s;
	int l = s.length();
	ll y = 1, ans = 0;
	loop(k + 1) {
		ll x = xp(26, k - i);
		ll z = xp(25, i) * y % mod;
		ans += x * z % mod;
		y = (y * (i + l) % mod) * inv(i + 1) % mod;
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}

