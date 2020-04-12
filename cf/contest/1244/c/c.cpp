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

auto eucl(ll a, ll b) {
	if (!b) return make_tuple(1ll, 0ll, a);
	ll x, y, m;
	tie(x, y, m) = eucl(b, a % b);
	return make_tuple(y, x - (a / b) * y, a);
}

auto diof(ll a, ll b, ll c) {
	ll x, y, m;
	tie(x, y, m) = eucl(a, b);
	if (c % m) return make_tuple(0ll, 0ll, 0ll);
	return make_tuple(x, y, m);
}

void add(ll& x, ll& y, ll& ka, ll& kb) {
	x += ka;
	y -= kb;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	ll n, p, d, w;
	cin >> n >> p >> d >> w;
	ll x, y;
	ll m;
	tie(x, y, m) = diof(w, d, p);
	if (m) {
		x *= p / m;
		y *= p / m;
		ll ka = w / m, kb = d / m;
		kb
		cout << x * w + d * y << endl;
	}
	else cout << -1 << endl;
	return 0;
}

