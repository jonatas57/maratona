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
#define N                  4 * MAX + 10
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define ceach(x, s)        for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2

int mex(int n, int k) {
	if (k & 1) {
		if (n <= 3) return n % 2;
		if (n == 4) return 2;
		if (n & 1) return 0;
		return (mex(n / 2, k) & 1 ? 2 : 1);
	}
	if (n <= 2) return n;
	return (n + 1) & 1;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, k, a;
	int ans = 0;
	cin >> n >> k;
	loop(n) cin >> a, ans ^= mex(a, k);
	cout << (ans ? "Kevin\n" : "Nicky\n");
	return 0;
}
