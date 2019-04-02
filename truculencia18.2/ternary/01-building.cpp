#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<ll>         vll;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f3f3f3f3f
#define each(x, s)         for(auto& x : s)
#define ceach(x, s)        for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define pb                 push_back
#define T                  100000
#define N                  4 * T + 10
#define avg(x, y)          x + (y - x) / 2
#define left(x)            x << 1
#define right(x)           x << 1 | 1

int n;
vi h, c;
ll f(int x) {
	ll ans = 0;
	loop(n) {
		ans += (ll)abs(x - h[i]) * c[i];
	}
	return ans;
}

ll ternary(int l, int r) {
	while (r - l >= 3) {
		int x = l + (r - l) / 3, y = r - (r - l) / 3;
		ll f1 = f(x), f2 = f(y);
		if (f1 >= f2) l = x;
		if (f1 <= f2) r = y;
	}
	ll ans = INF;
	rep(l, r + 1, 1) {
		ans = min(ans, f(i));
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		h.resize(n);c.resize(n);
		int minh = INF, maxh = 0;
		loop(n) cin >> h[i], minh = min(minh, h[i]), maxh = max(h[i], maxh);
		loop(n) cin >> c[i];
		cout << ternary(minh, maxh) << endl;
	}
	return 0;
}
