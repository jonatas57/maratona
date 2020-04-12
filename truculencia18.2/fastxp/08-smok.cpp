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

ll mod = 1000000007;

typedef vector<vector<ll>> matrix;

matrix operator*(matrix& a, matrix& b) {
  int n = a.size();
  matrix c(n, vector<ll>(n, 0));
  for (int i = 0;i < n;i++) {
    for (int j = 0;j < n;j++) {
      for (int k = 0;k < n;k++) {
        c[i][j] += a[i][k] * b[k][j];
        c[i][j] %= mod;
      }
    }
  }
  return c;
}
void operator*=(matrix& a, matrix& b) {
  a = a * b;
}
matrix operator^(matrix& a, int n) {
  if (n == 1) return a;
  matrix c = a ^ (n / 2);
  c *= c;
  if (n & 1) c *= a;
  return c;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;
	int a, b;
	matrix adj(n, vector<ll>(n, 0));
	loop(m) {
		cin >> a >> b;
		adj[a - 1][b - 1]++;
		if (a != b) adj[b - 1][a - 1]++;
	}
	matrix ans = adj ^ k;
	mod = 1e9 + 11;
	matrix ans2 = adj ^ k;
	loop(n - 1) {
		for (int j = i + 1;j < n;j++) {
			cout << (ans[i][j] or ans[i][j] != ans2[i][j] ? ans[i][j] : -1) << " ";
		}
		cout << endl;
	}
	return 0; 
}

