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

ll power(ll a, ll b) {
	if (b == 0) return 1;
	if (b == 1) return a;
	ll e = power(a, b / 2);
	e *= e;
	if (b & 1) e *= a;
	return e;
}

ll tot(ll n) {
	ll ans = n;
	for (ll i = 2;i * i <= n;i++) {
		if (n % i == 0) {
			while (n % i == 0) {
				n /= i;
			}
			ans -= ans / i;
		}
	}
	if (n > 1) {
		ans -= ans / n;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	ll n;
	while (scanf("%lld", &n) != EOF) {
		ll t = tot(n);
		printf("%lld\n", t / 2);
	}
	return 0;
}

