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

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, k;
	cin >> n >> k;
	vector<ll> a;
	int z = 0, x;
	loop(n) {
		cin >> x;
		if (x) a.push_back(x);
		else z++;
	}
	if (z + k > n) cout << 0 << endl;
	else {
		sort(iter(a), [](ll x, ll y) {
			return abs(x) == abs(y) ? x > y : abs(x) > abs(y);
		});
		int neg = 0, lastn = -1, lastp = -1;
		loop(k) {
			if (a[i] < 0) neg++, lastn = i;
			else lastp = i;
		}
		if (neg & 1) {
			int ok = 0;
			vector<pair<ll, ll>> ts;
			for (int i = k;ok < 3 and i < n - z;i++) {
				if (lastp != -1 and a[i] < 0 and not (ok & 1)) ts.emplace_back(a[i], a[lastp]), ok |= 1;
				else if (a[i] > 0 and not (ok & 2)) ts.emplace_back(a[i], a[lastn]), ok |= 2;
			}
			if (ok) {
				if (abs(ts[0].first) * abs(ts[1].second) < abs(ts[1].first) * abs(ts[0].second)) {
					swap(ts[0], ts[1]);
				}
				a[(ts[0].second > 0 ? lastp : lastn)] = ts[0].first;
			}
			else {
				if (z) a[0] = 0;
				else {
					sort(riter(a), [](ll x, ll y) {
						return abs(x) == abs(y) ? x > y : abs(x) > abs(y);
					});
				}
			}
		}
		ll ans = 1;
		loop(k) {
			if (a[i] < 0) a[i] += mod;
			ans *= a[i];
			ans %= mod;
		}
		if (ans < 0) ans += mod;
		cout << ans << endl;
	}
	return 0;
}

