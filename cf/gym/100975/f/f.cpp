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

ll xp(ll b, ll e, ll mod) {
	if (e == 0) return 1;
	if (e == 1) return b;
	ll c = xp(b, e >> 1, mod);
	c = c * c % mod;
	if (e & 1) c = c * b % mod;
	return c;
}

int tot(int m) {
	int ans = 1;
	for (int i = 2;i * i <= m;i++) {
		int k = 0;
		if (m % i == 0) {
			while (m % i == 0) {
				k++;
				m /= i;
			}
			ans *= xp(i, k - 1, 10000000) * (i - 1);
		}
	}
	if (m > 1) ans *= m - 1;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	ll n, mod;
	cin >> n >> mod;
	int ans;
	if (n < 25) {
		ans = xp(2, xp(2, n, 100000000), mod);
	}
	else {
		int t = tot(mod);
		int e = t + xp(2, n, t);
		ans = xp(2, e, 2);
	}
	cout << (ans + 1) % mod << endl;
	return 0;
}

