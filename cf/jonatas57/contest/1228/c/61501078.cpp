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

auto fats(ll x) {
	set<ll> fs;
	for (ll i = 2;i * i <= x;i++) {
		if (x % i == 0) {
			fs.insert(i);
			while (x % i == 0) {
				x /= i;
			}
		}
	}
	if (x > 1) fs.insert(x);
	return fs;
}

ll xp(ll b, ll e) {
	if (e == 0) return 1;
	if (e == 1) return b;
	ll c = xp(b, e / 2);
	c *= c;
	c %= MOD;
	if (e & 1) c *= b, c %= MOD;
	return c;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	ll x, n;
	cin >> x >> n;
	auto fs = fats(x);
	ll ans = 1;
	each(p, fs) {
		ll next = p;
		ll d = n / next;
		while (d) {
			ans *= xp(p, d);
			ans %= MOD;
			if (LLONG_MAX / p >= next) {
				next *= p;
				d = n / next;
			}
			else d = 0;
		}
	}
	cout << ans << endl;
	return 0;
}
