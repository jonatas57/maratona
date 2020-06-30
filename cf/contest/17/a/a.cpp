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
	vb isprime(n + 1, true);
	isprime[0] = isprime[1] = false;
	vi x, primes;
	for (int i = 2;i < n;i++) {
		if (isprime[i]) {
			for (int j = i + i;j <= n;j += i) isprime[j] = false;
			if (i != 2) {
				x.push_back(primes.back() + i + 1);
			}
			primes.push_back(i);
		}
	}
	int cnt = 0;
	each(y, x) {
		if (isprime[y]) cnt++;
		if (y > n) break;
	}
	cout << (cnt >= k ? "YES" : "NO") << endl;
	return 0;
}

