#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;
typedef tuple<ll, ll, ll>  lll;

#define INF                0x3f3f3f3f
#define each(x, s)         for(auto& x : s)
#define ceach(x, s)        for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i <= y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define pb                 push_back
#define avg(x, y)          x + (y - x) / 2

lll diof(ll a, ll b) {
	if (b == 0) return lll(1, 0, a);
	ll m, n, g;
	tie(m, n, g) = diof(b, a % b);
	return lll(n, m - (a / b) * n, g);
}

ll c1, c2, n1, n2, x, y;
ll cost(ll t) {
	return c1 * (x + t * n2) + c2 * (y - t * n1);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	ll n;
	while (cin >> n && n) {
		cin >> c1 >> n1 >> c2 >> n2;
		ll g;
		tie(x, y, g) = diof(n1, n2);
		if (n % g || n < n1 || n < n2) {
			cout << "failed\n";
		}
		else {
			x *= n / g;
			y *= n / g;
			ll t1 = -x / n2, t2 = y / n1;
			ll t = (cost(t1) < cost(t2) ? t1 : t2);
			x += t * n2;
			y -= t * n1;
			n2 /= g, n1 /= g;
			while (x < 0 || c1 * n2 < c2 * n1 && y - n1 > 0) x += n2, y -= n1;
			while (y < 0 || c1 * n2 > c2 * n1 && x - n2 > 0) y += n1, x -= n2;
			if (x < 0 || y < 0) cout << "failed\n";
			else cout << x << " " << y << endl;
		}
	}
	return 0;
}
