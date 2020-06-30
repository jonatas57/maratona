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
		sort(iter(a));
		int r = n - 1, r2 = n - 1;
		ll ans = 0;
		vi w(k);
		loop(k) {
			cin >> w[i];
			w[i]--;
			ans += a[r--];
		}
		sort(iter(w));
		loop(k) {
			if (w[i]) {
				vloop(j, w[i]) {
					if (j == w[i] - 1) ans += a[r];
					r--;
				}
			}
			else {
				ans += a[r2--];
			}
		}
		cout << ans << endl;
	}
	return 0;
}

