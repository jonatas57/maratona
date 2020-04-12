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

auto divs(ll x) {
	map<ll, ll> d;
	for (ll i = 2;i * i <= x;i++) {
		while (x % i == 0) {
			x /= i;
			d[i]++;
		}
	}
	if (x > 1) d[x]++;
	return d;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	loop(n) {
		ll a, b;
		cin >> a >> b;
		map<ll, ll> d1 = divs(a), d2 = divs(b);
		map<ll, pair<ll, ll>> d;
		for (auto& [k, v] : d1) {
			d[k] = {v, 0};
		}
		for (auto& [k, v] : d2) {
			d[k].second = v;
		}
		bool p = true;
		for (auto& [k, v] : d) {
			ll x, y;
			tie(x, y) = v;
			ll minx = x / 2 + (x & 1), miny = y / 2 + (y & 1);
			if ((x + y) % 3 != 0 || minx > y || miny > x) {
				p = false;
			}
		}
		cout << (p ? "YES" : "NO") << endl;
	}
	return 0;
}
