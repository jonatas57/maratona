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

#define MOD                1000000007
#define N                  100000

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

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	matrix m(4, vector<ll>(4, 1));
	loop(4) m[i][i] = 0;
	int n;
	cin >> n;
	m = m ^ n;
	cout << m[3][3] << endl;
	return 0;
}
