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

ll xp(ll b, int e) {
	if (e == 0) return 1;
	if (e == 1) return b;
	ll c = xp(b, e >> 1);
	c *= c;
	if (e & 1) c *= b;
	return c;
}

ll tot(ll m) {
	ll ans = 1;
	for (ll i = 2;i * i <= m;i++) {
		ll cnt = 0;
		while (m % i == 0) {
			cnt++;
			m /= i;
		}
		if (cnt > 0) ans *= xp(i, cnt - 1) * (i - 1);
	}
	if (m > 1) ans *= m - 1;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		ll a, m;
		cin >> a >> m;
		ll g = __gcd(a, m);
		m /= g;
		cout << tot(m) << endl;
	}
	return 0;
}

