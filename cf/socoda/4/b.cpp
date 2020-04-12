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

	ll n, k;
	cin >> n >> k;
	vector<ll> c(n);
	loop(n) cin >> c[i];
	sort(iter(c));
	for (int p = 0, r = 0;k and c[n - 1] - c[0] > 1;) {
		while (r < n and c[n - 1] == c[n - 1 - r]) r++;
		ll x = min((ll)r * (c[n - 1] - (r < n ? c[n - 1 - r] : 0)), k);
		for (ll s = x;s;) {
			if (s <= r) {
				for (int i = n - r;s and i < n;i++) c[i]--, s--;
			}
			else {
				ll y = s / (ll)r;
				for (int i = n - r;i < n;i++) c[i] -= y, s -= y;
			}
		}
		k -= x;
		while (x) {
			while (p < n and c[0] == c[p]) p++;
			if (x <= (ll)p) {
				for (int i = p - 1;x and i >= 0;i--) c[i]++, x--;
			}
			else {
				ll y = min(x / (ll)p, p < n ? c[p] - c[0] : INFLL);
				for (int i = p - 1;x and i >= 0;i--) c[i] += y, x -= y;
			}
		}
	}
	cout << c[n - 1] - c[0] << endl;
	return 0;
}

