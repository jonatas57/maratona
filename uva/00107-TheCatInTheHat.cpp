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
	if (e & 1) c *= b;
	return c;
}

map<ll, ll> fat(ll l) {
	map<ll, ll> fs;
	for (ll i = 2;i * i <= l;i++) {
		while (l % i == 0) {
			fs[i]++;
			l /= i;
		}
	}
	if (l > 1) fs[l]++;
	return fs;
}

vector<ll> divs(ll x) {
	vector<ll> ds;
	for (int i = 1;i * i <= x;i++) {
		if (x % i == 0) {
			ds.push_back(i);
			ds.push_back(x / i);
		}
	}
	sort(iter(ds));
	return ds;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	ll h, l;
	while (cin >> h >> l and h | l) {
		map<ll, ll> fs = fat(l);
		ll d = 0;
		each(p, fs) {
			d = __gcd(d, p.second);
		}
		ll n = 1;
		if (l == 1) {
			ll x = 1;
			while (x != h) x *= 2, d++;
		}
		else {
			each(p, fs) {
				n *= xp(p.first, p.second / d);
			}
		}
		each(x, divs(d)) {
			ll n2 = xp(n, x);
			ll d2 = d / x;
			if (xp(n2, d2) == l and xp(n2 + 1, d2) == h) {
				n = n2;
				d = d2;
				break;
			}
		}
		ll nw = n == 1 ? d : (l - 1) / (n - 1), sum = l;
		ll a = 1, b = 1;
		loop(d) {
			sum += a * h / b;
			a *= n;
			b *= n + 1;
		}
		cout << nw << " " << sum << endl;
	}
	return 0;
}
