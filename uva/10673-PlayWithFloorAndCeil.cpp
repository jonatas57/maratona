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

tuple<ll, ll, ll> eucl(ll a, ll b) {
	if (!b) return make_tuple(1, 0, a);
	ll x, y, g;
	tie(x, y, g) = eucl(b, a % b);
	return make_tuple(y, x - a / b * y, g);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		ll x, k;
		cin >> x >> k;
		ll f = x / k, c = f + (x % k > 0);
		ll m, n, g;
		tie(m, n, g) = eucl(f, c);
		m *= x / g, n *= x / g;
		cout << m << " " << n << endl;
	}
	return 0;
}

