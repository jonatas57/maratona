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

	vi primes(1, 1);
	vb isprime(1000, true);
	for (int i = 2;i < 1000;i++) {
		if (!isprime[i]) continue;
			for (int j = i + i;j < 1000;j += i) isprime[j] = false;
		primes.push_back(i);
	}

	int n, c;
	while (cin >> n >> c) {
		vi ans(primes.begin(), upper_bound(iter(primes), n));
		int sz = ans.size(), x = max(0, (sz + 1) / 2 - c);
		cout << n << " " << c << ":";
		for (int i = x;i < sz - x;i++) {
			cout << " " << ans[i];
		}
		cout << endl << endl;
	}
	return 0;
}

