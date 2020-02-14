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
 
 	int t;
	cin >> t;
	loop(t) {
		int n, k;
		cin >> n >> k;
		vector<ll> a(n);
		loop(n) cin >> a[i];
		vector<ll> acc(n + 1, 0), acc2(n + 1, 0), add(n + 1, 0);
		loop(n) {
			acc[i + 1] = acc[i] + a[i] % k;
			acc2[i + 1] = acc2[i] + a[i];
			add[n - i - 1] = add[n - i] + (k - a[n - i - 1] % k) % k;
		}
		ll ans = INFLL;
		loop(n + 1) {
			ll x = acc[i] - add[i], y = acc2[i] - add[i];
			if (x >= 0) ans = min(ans, x % k);
			if (y >= 0) ans = min(ans, y % k);
		}
		cout << ans << endl;
	}
	return 0;
}

