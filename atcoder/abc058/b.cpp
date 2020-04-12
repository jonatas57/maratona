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

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<ll> x(n), y(m);
	loop(n) cin >> x[i];
	loop(m) cin >> y[i];
	ll ans = 0, sum = 0;
	loop(n - 1) {
		ans += (x[i + 1] - x[i]) * (i + 1) * (n - i - 1);
		ans %= mod;
	}
	loop(m - 1) {
		sum += (y[i + 1] - y[i]) * (i + 1) * (m - i - 1);
		sum %= mod;
	}
	ans *= sum;
	ans %= mod;
	cout << ans << endl;
	return 0;
}
