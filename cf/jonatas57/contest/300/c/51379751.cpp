#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define MAX                100000
#define N                  4 * MAX + 10
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define ceach(x, s)        for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2

ii diof(int a, int b) {
	int s = 0, olds = 1;
	int t = 1, oldt = 0;
	int r = b, oldr = a;

	while (r) {
		int d = oldr / r;
		tie(oldr, r) = make_tuple(r, oldr - d * r);
		tie(olds, s) = make_tuple(s, olds - d * s);
		tie(oldt, t) = make_tuple(t, oldt - d * t);
	}
	return {olds, oldt};
}

int inv(int x, int m) {
	x %= m;
	int a, b;
	tie(a, b) = diof(x, m);
	if (a < 0) a += m;
	return a;
}

bool isgood(ll x, int a, int b) {
	while (x) {
		int r = x % 10;
		x /= 10;
		if (r != a && r != b) return false;
	}
	return true;
}

vector<ll> facs;
int comb(int n, int p) {
	ll x = facs[n], y = ((ll)facs[p] * facs[n - p]) % MOD;
	int in = inv(y, MOD);
	return (x * in) % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int a, b, n;
	cin >> a >> b >> n;
	facs.push_back(1ll);
	rep(1, n + 1, 1) facs.push_back((facs[i - 1] * i) % MOD);
	ll ans = 0;
	if (n == 1) cout << 2 << endl;
	else {
		loop(n / 2) {
			ll x = comb(n, i);
			if (isgood(i * a + (n - i) * b, a, b)) ans += x;
			if (isgood(i * b + (n - i) * a, a, b)) ans += x;
			ans %= MOD;
		}
		if (!(n & 1) && isgood((n / 2) * (a + b), a, b)) ans += comb(n / 2, n / 2);
		ans %= MOD;
		cout << ans << endl;
	}
	return 0;
}

