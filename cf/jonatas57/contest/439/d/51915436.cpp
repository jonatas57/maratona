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

int n, m;
vi a, b;
ll f(int x) {
	ll ans = 0;
	for (int i = 0;i < n && a[i] < x;i++) ans += x - a[i];
	for (int i = 0;i < m && b[i] > x;i++) ans += b[i] - x;
	return ans;
}

ll ternary(int l, int r) {
	if (r <= l) return 0;
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

	cin >> n >> m;
	a.resize(n);
	b.resize(m);
	loop(n) cin >> a[i];
	loop(m) cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.rbegin(), b.rend());
	cout << ternary(a[0], b[0]) << endl;
	return 0;
}
