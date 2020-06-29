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

pair<ll, ll> eucl(ll a, ll b) {
	if (b == 0) return make_pair(1ll, 0ll);
	ll x, y;
	tie(x, y) = eucl(b, a % b);
	return make_pair(y, x - a / b * y);
}

ll inv(ll x) {
	ll y;
	tie(y, ignore) = eucl(x, mod);
	return (y % mod + mod) % mod;
}

ll eval(pair<ll, ll>& p) {
	return p.first * inv(p.second) % mod;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int h, w, a, b;
	cin >> h >> w >> a >> b;
	ll ans = 0;
	vector<pair<ll, ll>> c1(1, {1, 1}), c2(1, {1, 1});
	ll n1 = h - a - 1, n2 = a - 1;
	for (int i = 1;i <= w;i++) {
		c1.emplace_back(c1[i - 1].first * (n1 + i) % mod, c1[i - 1].second * i % mod);
		c2.emplace_back(c2[i - 1].first * (n2 + i) % mod, c2[i - 1].second * i % mod);
	}
	for (int i = b;i < w;i++) {
		ans += eval(c1[i]) * eval(c2[w - i - 1]) % mod;
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}

