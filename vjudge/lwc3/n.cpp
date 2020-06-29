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

mii fats(int x) {
	mii fs;
	for (int i = 2;i * i <= x;i++) {
		while (x % i == 0) {
			fs[i]++;
			x /= i;
		}
	}
	if (x > 1) fs[x]++;
	return fs;
}

pair<ll, ll> eucl(ll a, ll b) {
	if (b == 0) return make_pair(1ll, 0ll);
	ll x, y;
	tie(x, y) = eucl(b, a % b);
	return make_pair(y, x - a / b * y);
}

ll inv(ll a) {
	ll x;
	tie(x, ignore) = eucl(a, mod);
	return (x % mod + mod) % mod;
}

ll choose(ll n, ll k) {
	k = min(k, n - k);
	ll a = 1, b = 1;
	loop(k) {
		a *= n - i;
		b *= i + 1;
		a %= mod;
		b %= mod;
	}
	return a * inv(b) % mod;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	mii fs = fats(m);
	ll ans = 1;
	each(p, fs) {
		ans *= choose(p.second + n - 1, n - 1);
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}

