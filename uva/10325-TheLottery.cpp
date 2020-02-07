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

ll lcm(vector<ll>& a) {
	int n = a.size();
	ll ans = a[0];
	for (int i = 1;i < n;i++) {
		ll m = __gcd(ans, a[i]);
		ans *= a[i] / m;
	}
	return ans;
}

vector<ll> mask(int x) {
	vector<ll> ans;
	for (int i = 0;x;i++) {
		if (x & 1) ans.push_back(i);
		x >>= 1;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	ll n, m;
	while (cin >> n >> m) {
		vector<ll> a(m);
		loop(m) cin >> a[i];
		int maxmask = 1 << m;
		ll ans = n;
		for (int i = 1;i < maxmask;i++) {
			vector<ll> p = mask(i);
			each(x, p) x = a[x];
			ll mmc = lcm(p);
			ll div = n / mmc;
			ans += (p.size() & 1 ? -div : div);
		}
		cout << ans << endl;
	}
	return 0;
}

