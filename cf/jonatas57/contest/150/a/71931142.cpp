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
#define iter(a)            a.begin(), a.end()

auto fats(ll q) {
	map<ll, int> cnt;
	ll x = 1;
	for (ll i = 2;i * i <= q;i++) {
		if (q % i == 0) {
			while (q % i == 0) {
				cnt[i]++;
				q /= i;
			}
			x *= cnt[i] + 1;
		}
	}
	if (q > 1) cnt[q]++, x *= 2;
	return make_pair(vector<pair<ll, int>>(iter(cnt)), x);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	ll q;
	cin >> q;
	vector<pair<ll, int>> fs;
	ll x;
	tie(fs, x) = fats(q);
	if (x <= 2) {
		cout << 1 << endl << 0 << endl;
	}
	else {
		ll ans = fs[0].first * fs[fs[0].second == 1].first;
		if (ans == q) cout << 2 << endl;
		else cout << 1 << endl << ans << endl;
	}
	return 0;
}

