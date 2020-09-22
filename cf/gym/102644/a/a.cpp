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
	double size;
	vector<vector<double>> m;
	matrix(int n, double val = 0) : size(n), m(n, vector<double>(n, val)) {}
	matrix operator*(matrix& b) {
		matrix c(size);
		loop(size) vloop(j, size) vloop(k, size) {
			c[i][j] += m[i][k] * b[k][j];
		}
		return c;
	}
	vector<double>& operator[](int i) {
		return m[i];
	}
};

matrix xp(matrix& b, int e) {
	if (e == 1) return b;
	matrix c = xp(b, e >> 1);
	c = c * c;
	if (e & 1) c = c * b;
	return c;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	double p;
	cin >> n >> p;
	matrix m(2);
	m[0][0] = m[1][1] = 1 - p;
	m[0][1] = m[1][0] = p;
	m = xp(m, n);
	cout << fixed << setprecision(10) << m[0][0] << endl;
	return 0;
}

