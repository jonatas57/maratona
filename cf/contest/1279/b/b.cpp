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

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		ll n, s;
		cin >> n >> s;
		vector<ll> a(n), acc(n + 1, 0);
		vector<pair<ll, ll>> maxi(n + 1, {0, 0});
		loop(n) {
			cin >> a[i];
			acc[i + 1] = acc[i] + a[i];
			maxi[i + 1] = max(maxi[i], {a[i], i + 1});
		}
		ll ans = 0, val = 0;
		loop(n) {
			ll v, p;
			tie(v, p) = maxi[i + 1];
			ll x = acc[i + 1] - v;
			if (x > val and x <= s) {
				ans = p;
				val = x;
			}
		}
		if (acc[n] > val and acc[n] <= s) ans = 0;
		cout << ans << endl;
	}
	return 0;
}
