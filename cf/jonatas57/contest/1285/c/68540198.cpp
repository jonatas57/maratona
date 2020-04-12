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

ll xp(ll b, ll e) {
	if (e == 0) return 1;
	if (e == 1) return b;
	ll c = xp(b, e >> 1);
	c *= c;
	if (e & 1) c *= b;
	return c;
}

auto fats(ll x) {
	map<ll, int> fs;
	for (ll i = 2;i * i <= x;i++) {
		while (x % i == 0) {
			fs[i]++;
			x /= i;
		}
	}
	if (x > 1) fs[x]++;
	return fs;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	ll x;
	cin >> x;
	ll p = 1, q = 1;
	auto fs = fats(x);
	vector<ll> aux;
	for (auto& [b, e] : fs) {
		aux.push_back(xp(b, e));
	}
	sort(riter(aux));
	int l = aux.size();
	ll m = INFLL;
	loop(1 << l) {
		ll a = 1, b = 1, z = 0;
		vloop(j, l) {
			if (i & (1 << j)) a *= aux[j];
			else b *= aux[j];
		}
		z = max(a, b);
		if (m > z) {
			m = z;
			p = a;
			q = b;
		}
	}
	cout << p << " " << q << endl;
	return 0;
}

