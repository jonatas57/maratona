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
#define N                  1000001
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define ceach(x, s)        for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2

vb ps;
vi primes;
void getprimes() {
	ps.resize(N, true);
	ps[0] = ps[1] = false;
	for (int i = 2;i < N;i++) {
		if (!ps[i]) continue;
		primes.push_back(i);
		for (int j = 2 * i;j < N;j += i) {
			ps[j] = false;
		}
	}
}

int div(ll x) {
	int ans = 1;
	each(p, primes) {
		if (x == 1) break;
		int c = 0;
		while (x % p == 0) {
			x /= p;
			c++;
		}
		ans *= c + 1;
	}
	return ans - 2;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	getprimes();
	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		vector<ll> d(n);
		loop(n) {
			cin >> d[i];
		}
		sort(d.begin(), d.end());
		ll x = d[0] * d[n - 1];
		bool p = true;
		int aux = n / 2;
		loop(aux + 1) if (d[i] * d[n - i - 1] != x) p = false;
		if (div(x) != n) p = false;
		cout << (p ? x : -1) << endl;
	}
	return 0;
}

