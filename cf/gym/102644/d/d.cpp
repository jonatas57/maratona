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

	ll n, m, k;
	cin >> n >> m >> k;
	matrix adj(n);
	int u, v;
	loop(m) {
		cin >> u >> v;
		adj[u - 1][v - 1]++;
	}
	adj = xp(adj, k);
	ll ans = 0;
	each(v, adj.m) {
		each(x, v) {
			ans += x;
			ans %= mod;
		}
	}
	cout << ans << endl;
	return 0;
}
