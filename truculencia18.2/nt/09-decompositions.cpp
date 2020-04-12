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

auto eucl(ll a, ll b) {
	if (!b) return make_pair(1ll, 0ll);
	ll x, y;
	tie(x, y) = eucl(b, a % b);
	return make_pair(y, x - (a / b) * y);
}

ll inv(ll x) {
	ll y;
	tie(y, ignore) = eucl(x, mod);
	if (y < 0) y += mod;
	return y;
}

mii fat(int x) {
	mii fs;
	for (int i = 2;i * i <= x;i++) {
		while (x % i == 0) {
			x /= i;
			fs[i]++;
		}
	}
	if (x > 1) fs[x]++;
	return fs;
}

ll choose(ll n, ll k) {
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

	int n;
	cin >> n;
	mii ps;
	loop(n) {
		int x;
		cin >> x;
		auto fs = fat(x);
		for (auto& [p, e] : fs) ps[p] += e;
	}
	ll ans = 1;
	for (auto& [p, q] : ps) {
		ans *= choose(q + n - 1, n - 1);
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}

