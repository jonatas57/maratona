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

struct matrix {
	int size;
	vector<vector<ll>> m;
	matrix(int n, ll val = 0) : size(n), m(n, vector<ll>(n, val)) {}
	matrix operator*(matrix& b) {
		matrix c(size);
		loop(size) vloop(j, size) vloop(k, size) {
			c[i][j] += m[i][k] * b[k][j];
			c[i][j] %= mod;
		}
		return c;
	}
	vector<ll>& operator[](int i) {
		return m[i];
	}
};

matrix xp(matrix& b, ll e) {
	if (e == 1) return b;
	matrix c = xp(b, e >> 1);
	c = c * c;
	if (e & 1) c = c * b;
	return c;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	ll k;
	cin >> n >> k;
	matrix m(n + 3);
	vector<ll> a(n + 3);
	a[n] = n * n % mod;
	a[n + 1] = n;
	a[n + 2] = 1;
	loop(n) cin >> a[n - 1 - i];
	loop(n) cin >> m[0][i];
	loop(3) cin >> m[0][n + 2 - i];
	loop(n - 1) m[i + 1][i] = 1;
	m[n][n] = m[n + 1][n + 1] = m[n + 2][n + 2] = m[n][n + 2] = m[n + 1][n + 2] = 1;
	m[n][n + 1] = 2;

	if (k < n) cout << a[n - 1 - k] << endl;
	else {
		m = xp(m, k - n + 1);
		ll ans = 0;
		loop(n + 3) {
			ans += m[0][i] * a[i];
			ans %= mod;
		}
		cout << ans << endl;
	}
	return 0;
}
