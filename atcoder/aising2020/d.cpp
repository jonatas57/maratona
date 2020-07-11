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

vi memo(200005, -1);

int solve(int x) {
	if (memo[x] == -1) {
		memo[x] = 1 + solve(x % __builtin_popcount(x));
	}
	return memo[x];
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	memo[0] = 0;
	int n;
	string s;
	cin >> n >> s;
	int x1 = 0, x2 = 0, pop = 0;
	each(c, s) pop += c == '1';
	each(c, s) {
		x1 <<= 1;
		x2 <<= 1;
		if (c == '1') {
			x1++;
			x2++;
		}
		if (pop <= 1) x1 = 0;
		else if (x1 >= pop - 1) x1 %= pop - 1;
		if (x2 >= pop + 1) x2 %= pop + 1;
	}
	vi y(n);
	vb zero(n, false);
	for (int i = n - 1, b1 = 1, b2 = 1;i >= 0;i--, b1 <<= 1, b2 <<= 1) {
		if (pop <= 1) b1 = 0;
		else if (b1 >= pop - 1) b1 %= pop - 1;
		if (b2 >= pop + 1) b2 %= pop + 1;
		if (s[i] == '1') {
			if (pop <= 1) y[i] = 0, zero[i] = true;
			else y[i] = (x1 + pop - 1 - b1) % (pop - 1);
		}
		else y[i] = (x2 + b2) % (pop + 1);
	}
	loop(n) cout << (zero[i] ? 0 : 1 + solve(y[i])) << endl;
	return 0;
}

