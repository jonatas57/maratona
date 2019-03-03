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
int chg(char c) {
	if (c >= 'a') return 1 + c - 'a';
	else return c - 'A' + 27;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	ll n;
	int m, k;
	cin >> n >> m >> k;
	matrix mat(m + 2, vector<ll>(m + 2, 1));
	loop(m + 2) {
		mat[m + 1][i] = mat[i][0] = 0;
	}
	string x;
	loop(k) {
		cin >> x;
		mat[chg(x[0])][chg(x[1])] = 0;
	}
	mat = mat ^ (n + 1);
	cout << mat[0][m + 1] << endl;
	return 0;
}
