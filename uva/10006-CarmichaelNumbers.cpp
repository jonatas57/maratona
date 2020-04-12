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

ll xp(ll b, ll e, ll m) {
	if (e == 0) return 1;
	ll c = xp(b, e >> 1, m);
	c = (c * c) % m;
	if (e & 1) c = (c * b) % m;
	return c;
}

bool prime(int n) {
	for (int i = 2;i * i <= n;i++) {
		if (n % i == 0) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	vb prime(65001, true);
	prime[0] = prime[1] = false;
	for (int i = 2;i < 65001;i++) {
		if (!prime[i]) continue;
		for (int j = i << 1;j < 65001;j += i) prime[j] = false;
	}
	while (cin >> n and n) {
		bool p = !prime[n];
		for (int i = 2;i < n and p;i++) {
			p = xp(i, n, n) == i;
		}
		if (p) cout << "The number " << n << " is a Carmichael number." << endl;
		else cout << n << " is normal." << endl;
	}
	return 0;
}

