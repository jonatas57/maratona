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

ll dp[1 << 18][18];

int adj[20][20];
void addEdge(int a, int b, int c) {
	adj[a][b] = c;
}

int count(int x) {
	int c = 0;
	while (x) {
		x -= (x & -x);
		c++;
	}
	return c;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;
	int lim = 1 << n;
	vi a(n);
	loop(n) {
		cin >> a[i];
		dp[1 << i][i] = a[i];
	}
	loop(k) {
		int a, b, c;
		cin >> a >> b >> c;
		adj[a - 1][b - 1] = c;
	}
	ll ans = 0;
	vloop(mask, lim) {
		int cnt = count(mask);
		loop(n) {
			if (mask & (1 << i)) {
				vloop(j, n) {
					int x = 1 << j;
					if (!(mask & x)) {
						dp[mask | x][j] = max(dp[mask | x][j], dp[mask][i] + a[j] + adj[i][j]);
					}
				}
			}
			if (cnt == m) ans = max(ans, dp[mask][i]);
		}
	}
	cout << ans << endl;
	return 0;
}

