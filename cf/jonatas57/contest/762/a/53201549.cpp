#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define MAX                100000
#define N                  4 * MAX + 10
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define ceach(x, s)        for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2

vector<ll> divs(ll n) {
	set<ll> d;
	for (ll i = 1;i * i <= n;i++) {
		if (n % i == 0) {
			d.insert(i);
			d.insert(n / i);
		}
	}
	return vector<ll>(d.begin(), d.end());
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	ll n, k;
	cin >> n >> k;
	auto div = divs(n);
	if (div.size() < k) cout << -1 << endl;
	else cout << div[k - 1] << endl;
	return 0;
}
