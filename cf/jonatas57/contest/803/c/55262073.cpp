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

vi divs(ll n, ll aux) {
	vi ds;
	ll x;
	for (ll i = 1;i <= aux && i * i <= n;i++) {
		if (n % i == 0) {
			ds.push_back(i);
			if ((x = n / i) <= aux) ds.push_back(x);
		}
	}
	sort(ds.begin(), ds.end());
	return ds;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	ll n, k;
	cin >> n >> k;
	bool p;
	if ((p = k <= 200000)) {
		vector<ll> a(k);
		ll kk = 0;
		loop(k) a[i] = i + 1, kk += i + 1;
		if ((p = p && n >= kk)) {
			ll aux = n / kk;
			vi ds = divs(n, aux);
			int id = ds.size() - 1;
			for (;id >= 0 && ds[id] * kk > n;id--);
			ll gcd = ds[id];
			if ((p = p && kk * gcd <= n)) {
				loop(k) a[i] *= gcd;
				a[k - 1] += n - kk * gcd;
				each(x, a) cout << x << " ";
				cout << endl;
			}
		}
	}
	if (!p) cout << -1 << endl;
	return 0;
}
