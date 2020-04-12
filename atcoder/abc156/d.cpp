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
	if (e == 1) return b;
	ll c = xp(b, e >> 1);
	c *= c;
	c %= mod;
	if (e & 1) c *= b, c %= mod;
	return c;
}

pair<ll, ll> eucl(ll a, ll b) {
	if (!b) return {1ll, 0ll};
	ll x, y;
	tie(x, y) = eucl(b, a % b);
	return {y, x - a / b * y};
}

ll inv(ll x) {
	ll n, m;
	tie(n, m) = eucl(x, mod);
	if (n < 0) {
		n %= mod;
		if (n < 0) n += mod;
	}
	return n;
}

ll choose(ll n, ll k) {
	ll a = 1, b = 1;
	loop(k) {
		a *= n - i;
		a %= mod;
		b *= i + 1;
		b %= mod;
	}
	return a * inv(b) % mod;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, a, b;
	cin >> n >> a >> b;
	ll ans = xp(2, n) - 1;
	ans -= choose(n, a) + choose(n, b);
	ans %= mod;
	if (ans < 0) ans += mod;
	cout << ans << endl;
	return 0;
}

