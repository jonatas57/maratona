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

auto find(ll x) {
	ll s = log2(x);
	x -= (1 << s);
	return make_pair(x, s);
}

ll exp(ll b, ll e) {
	if (e == 0) return 1;
	if (e == 1) return b;
	ll c = exp(b, e / 2);
	c *= c;
	c %= MOD;
	if (e & 1) c *= b, c %= MOD;
	return c;
}

ll get(ll p, ll n, ll g) {
	ll pg = (n ? (exp(4, n) - 1) / 3 : 0);
	ll ans = (g ? 4 * pg + 2 * (p + 1) : 2 * (pg + p + 1) - 1);
	return ans;
}

auto parse(pair<ll, ll> q, bool f = true) {
	ll p, x;
	tie(p, x) = q;
	ll g = x & 1, n = x / 2;
	ll g2 = g ^ 1, n2 = n + (f ? g : -g2), p2 = (f ? 0 : exp(2, x - 1) - 1);
	auto ans = make_pair(get(p, n, g), get(p2, n2, g2));
	if (g) swap(ans.first, ans.second);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	ll l, r;
	cin >> l >> r;
	ll x, y, x2, y2;
	tie(x, x2) = parse(find(l)), tie(y, y2) = parse(find(r), false);/*@*/cerr << x << " " << y << " " << x2 << " " << y2 << endl;/*@*/
	x = x / 2 % MOD;
	y = y / 2 % MOD;
	x2 = x2 / 2 % MOD;
	y2 = y2 / 2 % MOD;/*@*/cerr << x << " " << y << " " << x2 << " " << y2 << endl;/*@*/
	ll ans = exp(y + 1, 2) - exp(x, 2) + (y2 * (y2 + 1)) % MOD - (x2 * (x2 - 1)) % MOD;
	ans %= MOD;
	cout << ans << endl;
	return 0;
}

