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

struct par {
	ll x, y;
	par(ll x, ll y) : x(x), y(y) {}
	bool operator<(const par& p) const {
		return x < p.x;
	}
};

ll xp(ll b, ll e) {
	if (e == 0) return 1;
	ll c = xp(b, e >> 1);
	c *= c;
	if (e & 1) c *= b;
	return c;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	ll n;
	cin >> n;

	vb isprime(n + 1, true);
	int psz = 0;
	vector<ll> primes, lp(n + 1, 0), cnt(n + 1, 0);
	isprime[0] = isprime[1] = false;
	for (int i = 2; i <= n;i++) {
		if (lp[i] == 0) {
			lp[i] = i;
			primes.push_back(i);
			psz++;
		}
		for (int j = 0;j < psz and primes[j] <= lp[i] and i * primes[j] <= n;j++) {
			lp[i * primes[j]] = primes[j];
		}
		cnt[i] = (lp[i] == lp[i / lp[i]] ? cnt[i / lp[i]] + 1 : 1);
	}
	ll ans = 0;
	for (ll i = 1;i <= n;i++) {
		ll d = 1, x = i;
		while (x > 1) {
			d *= cnt[x] + 1;
			x /= xp(lp[x], cnt[x]);
		}
		ans += d * i;
	}
	cout << ans << endl;
	return 0;
}

