#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define each(x, s)         for(auto& x : s)
#define ceach(x, s)        for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define pb                 push_back
#define avg(x, y)          x + (y - x) / 2

#define T                  1000000000000
#define N                  1000000
#define HN                 500000
vb prime;
vector<ll> almost;

void getprimes() {
	prime.resize(N, true);
	prime[0] = prime[1] = false;
	for (int i = 2;i < N;i++) {
		if (!prime[i]) continue;
		for (int j = 2 * i;j < N;j += i) {
			prime[j] = false;
		}
	}
}
void getAlmost() {
	for (ll i = 2;i < N;i++) {
		if (prime[i]) {
			for (ll j = i * i;j < T;j *= i) {
				almost.push_back(j);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	getprimes();
	getAlmost();
	sort(almost.begin(), almost.end());
	int n;
	cin >> n;
	loop(n) {
		if (i > 0) cout << endl;
		ll l, r;
		cin >> l >> r;
		auto x = lower_bound(almost.begin(), almost.end(), l),
		     y = upper_bound(almost.begin(), almost.end(), r);
		cout << y - x << endl;
	}
	return 0;
}
