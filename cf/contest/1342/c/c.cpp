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

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		ll a, b, q;
		cin >> a >> b >> q;
		if (a < b) swap(a, b);
		ll x = lcm(a, b), l, r;
		loop(q) {
			cin >> l >> r;
			ll ml = l - l % x;
			ll mr = r - r % x;
			ll ans = ((mr - ml) / x + 1) * a;
			if (ml < l) ans -= min(a, l - ml);
			if (mr + a - 1 > r) ans -= mr + a - 1 - r;
			ans = r - l + 1 - ans;
			cout << ans << " ";
		}
		cout << endl;
	}
	return 0;
}

