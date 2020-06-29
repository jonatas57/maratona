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
const int N = 2e7;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	vector<ii> twins;
	vi primes(1, 2);
	vb isprime(N, true);
	isprime[0] = isprime[1] = false;
	for (int i = 2;i < N;i++) {
		if (!isprime[i]) continue;
		if (primes.back() + 2 == i) twins.emplace_back(primes.back(), i);
		primes.push_back(i);
		for (int j = i + i;j < N;j += i) isprime[j] = false;
	}

	int n;
	while (cin >> n) {
		cout << "(" << twins[n - 1].first << ", " << twins[n - 1].second << ")" << endl;
	}
	return 0;
}

