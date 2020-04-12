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

const ll mod = 998244353;

auto eucl(ll a, ll b) {
	if (!b) return make_tuple(1ll, 0ll, a);
	ll x, y, d;
	tie(x, y, d) = eucl(b, a % b);
	return make_tuple(y, x - (a / b) * y, d);
}

ll inv(ll x, ll mod) {
	ll n = get<0>(eucl(x, mod));
	n %= mod;
	if (n < 0) n += mod;
	return n;
}

struct frac {
	ll n, d;
	frac(ll n = 0, ll d = 1) : n(n), d(d) {
		simpl();
	}

	void simpl() {
		ll m = __gcd(n, d);
		n /= m;
		d /= m;
		if (n > mod) n %= mod;
		if (d > mod) d %= mod;
	}

	void operator*=(frac f) {
		n *= f.n;
		d *= f.d;
		simpl();
	}

	void operator+=(frac f) {
		n = n * f.d + d * f.n;
		d *= f.d;
		simpl();
	}
};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	ll n;
	cin >> n;
	vector<vector<ll>> kids(n);
	vector<ll> cnt(1e6 + 1, 0);
	ll k, a;
	loop(n) {
		cin >> k;
		kids[i].push_back(k);
		vloop(j, k) {
			cin >> a;
			cnt[a]++;
			kids[i].push_back(a);
		}
	}
	frac ans;
	each(kid, kids) {
		frac p;
		for (ll i = 1;i <= kid[0];i++) {
			p += frac(cnt[kid[i]], n);
		}
		p *= frac(1, n * kid[0]);
		ans += p;
	}
	cout << (ans.n * inv(ans.d, mod)) % mod << endl;
	return 0;
}

