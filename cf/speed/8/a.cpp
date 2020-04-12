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

double prob(ii a) { return (double)a.second / a.first; }

int main() {
	ll n, p;
	cin >> n >> p;
	vector<ii> a;
	ll l, r;
	loop(n) {
		cin >> l >> r;
		ll x = r - l + 1;
		if (l % p) l = (l / p + 1) * p;
		r -= r % p;
		ll y = max(0ll, (r - l) / p + 1);
		a.emplace_back(x, y);
	}
	double ans = 0;
	loop(n) {
		int x = i ? i - 1 : n - 1, y = i == n - 1 ? 0 : i + 1;
		double p1 = prob(a[x]), p2 = prob(a[i]), p3 = prob(a[y]);
		 ans += 1000 * (p1 + p3 + p2 * (2 - p1 - p3));
	}
	printf("%.9f\n", ans);
	return 0;
}
