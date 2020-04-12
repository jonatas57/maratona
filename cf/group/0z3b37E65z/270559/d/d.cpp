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

int middle(string x) {
	int n = x.length();
	string y = x.substr(1, n - 2);
	return y.empty() ? 0 : stoi(y, nullptr, 10);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	vi primes(1, 2), pal(1, 1);
	int cntp = 0, cntr = 0;
	int p, q;
	cin >> p >> q;
	int i, ans = -1;
	for (i = 1;i <= 2e6;i++) {
		if (i > 1) {
			bool prime = true;
			for (int j = 0;primes[j] * primes[j] <= i;j++) {
				if (i % primes[j] == 0) {
					prime = false;
					break;
				}
			}
			if (prime) primes.push_back(i), cntp++;
		}
		if (i >= 10) {
			string x = to_string(i);
			pal.push_back(x[0] == x.back() and pal[middle(x)]);
		}
		else pal.push_back(1);
		cntr += pal.back();
		if (q * cntp <= p * cntr) ans = i;
	}
	if (ans == -1) << endl;
	return 0;
}

