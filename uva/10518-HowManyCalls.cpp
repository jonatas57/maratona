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

ll mod;

typedef vector<vi> matrix;

matrix operator*(matrix& a, matrix& b) {
	int n = a.size();
	matrix c(n, vi(n, 0));
	loop(n) vloop(j, n) vloop(k, n) {
		c[i][j] += a[i][k] * b[k][j];
		c[i][j] %= mod;
	}
	return c;
}

matrix xp(matrix& b, ull e) {
	if (e == 1) return b;
	matrix c = xp(b, e >> 1);
	c = c * c;
	if (e & 1) c = c * b;
	return c;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	ull n;
	matrix f = {{1, 1, 1}, {1, 0, 0}, {0, 0, 1}};
	for (int i = 1;cin >> n >> mod and n | mod;i++) {
		ll ans = 1;
		if (n > 1) {
			matrix c = xp(f, n - 1);
			ans = c[0][0] + c[0][1] + c[0][2];
			ans %= mod;
		}
		cout << "Case " << i << ": " << n << " " << mod << " " << ans << endl;
	}
	return 0;
}

