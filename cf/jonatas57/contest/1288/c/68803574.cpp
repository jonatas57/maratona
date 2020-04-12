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

vector<vi> memo(1015, vi(1015, -1));

ll choose(ll n, ll k) {
	if (k == 0 or n == k) return 1;
	if (k == 1) return n;
	if (memo[n][k] != -1) return memo[n][k];
	return memo[n][k] = (choose(n - 1, k) + choose(n - 1, k - 1)) % mod;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	memo[0][0] = 1;
	int n, m;
	cin >> n >> m;
	ll ans = 0;
	for (int i = 1;i <= n;i++) {
		ll x = choose(i + m - 2, i - 1) * choose(n + m - i, n - i);
		ans += x % mod;
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}

