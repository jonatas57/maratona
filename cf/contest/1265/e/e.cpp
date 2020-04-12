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
#define MOD                998244353
#define each(x, s)         for(auto& x : s)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

struct frac {
  ll n, d;
	frac(int n = 0, int d = 1) : n(n), d(d) {
		simpl();
	}
	void simpl() {
		ll m = __gcd(n, d);
		n /= m;
		d /= m;
		n %= MOD;
		d %= MOD;
		if (d < 0) *this = *this * -1;
	}
	frac operator*(ll x) {
		return frac(n * x, d);
	}
	void operator*=(frac f) {
		n *= f.n;
		d *= f.d;
		simpl();
	}
	frac operator*(frac f) {
		frac g = f;
		g *= *this;
		return g;
	}
	frac operator+(frac f) {
		return frac(n * f.d + d * f.n, d * f.d);
	}
	void operator/=(frac f) {
		*this *= f.inv();
	}
	frac inv() {
		return frac(d, n);
	}
};

auto eucl(ll a, ll b) {
	if (b == 0) return make_pair(1ll, 0ll);
	ll x, y;
	tie(x, y) = eucl(b, a % b);
	return make_pair(y, x - a / b * y);
}

ll inv(ll a, ll m) {
	ll x;
	tie(x, ignore) = eucl(a, m);
	while (x < 0) {
		x %= MOD;
		if (x < 0) x += MOD;
	}
	return x;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	vector<frac> ms;
	int p;
	frac P(1, 0), Q;
	loop(n) {
		cin >> p;
		ms.emplace_back(p, 100);
		Q = Q + P * frac(100 - p, 100);
		P *= ms[i];
	}/*@*/
	cerr << "P = " << P.n << "/" << P.d << endl;
	cerr << "Q = " << Q.n << "/" << Q.d << endl;/*@*/
	frac ans = P * Q, aux = frac(1) + (Q * -1);
	aux *= aux;
	ans /= aux;
	ll res = ans.n * inv(ans.d, MOD);
	res %= MOD;/*@*/
	cerr << ans.n << " "<< ans.d << endl;/*@*/
	cout << res << endl;
	return 0;
}

