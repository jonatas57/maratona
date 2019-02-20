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

#define MOD                1000000009

typedef vector<vector<ll>> matrix;

matrix operator*(matrix& a, matrix& b) {
	int n = a.size(), m = b.size(), p = a[0].size();
	matrix c(n, vector<ll>(n));
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			c[i][j] = 0;
			for (int k = 0;k < p;k++) {
				c[i][j] += (a[i][k] * b[k][j]) % MOD;
				c[i][j] %= MOD;
			}
		}
	}
	return c;
}
matrix operator^(matrix& a, ll n) {
	if (n == 1) return a;
	matrix c = a ^ (n / 2);
	c = c * c;
	if (n % 2) c = c * a;
	return c;
}

matrix tri = {{1,1,1},{1,0,0},{0,1,0}};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	ll n;
	vi f = {2, 1, 0};
	while (cin >> n && n) {
		if (n <= 3) {
			cout << f[3 - n] << endl;
			continue;
		}
		matrix c = tri ^ (n - 3);
		int x = 0;
		loop(3) {
			x += (c[0][i] * f[i]) % MOD;
			x %= MOD;
		}
		cout << x << endl;
	}
	return 0;
}
