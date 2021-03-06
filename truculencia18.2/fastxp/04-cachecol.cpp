#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>        vi;
typedef vector<ull>        vull;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define MOD                1000000007
#define each(x, s)         for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i += z)
#define loop(x)            for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)

#define pb                 push_back
#define eb                 emplace_back

typedef vector<vull> matrix;

matrix operator*(matrix& a, matrix& b) {
  int n = a.size();
  matrix c(n, vull(n));
  for (int i = 0;i < n;i++) {
    for (int j = 0;j < n;j++) {
      c[i][j] = 0;
      for (int k = 0;k < n;k++) {
        c[i][j] += a[i][k] * b[k][j];
        c[i][j] %= MOD;
      }
    }
  }
  return c;
}
void operator*=(matrix& a, matrix& b) {
  a = a * b;
}
matrix operator^(matrix& a, ull n) {
  if (n == 1) return a;
  matrix c = a ^ (n / 2);
  c *= c;
  if (n % 2) c *= a;
  return c;
}

matrix rec = {{3, 2}, {2, 2}};

int main() {
  ios_base::sync_with_stdio(false);

	ull n;
	cin >> n;
	matrix base = {{6}, {6}};
	if (n == 1) cout << 12 << endl;
	else {
		matrix x = rec ^ (n - 1);
		base = x * base;
		cout << (base[0][0] + base[1][0]) % MOD << endl;
	}
  return 0;
}
