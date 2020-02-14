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

int eval(char c) {
	return c - (isupper(c) ? 'A' - 27 : 'a' - 1);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	vb isprime(1041, true);
	isprime[0] = false;
	for (int i = 2;i < 1041;i++) {
		if (!isprime[i]) continue;
		for (int j = 2 * i;j < 1041;j += i) {
			isprime[j] = false;
		}
	}
	string s;
	while (cin >> s) {
		int x = 0;
		each(c, s) x += eval(c);
		cout << "It is" << (isprime[x] ? "" : " not") << " a prime word." << endl;
	}
	return 0;
}

