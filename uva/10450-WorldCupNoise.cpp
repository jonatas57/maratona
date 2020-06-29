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

int sz = 2;
vector<vector<ll>> operator*(vector<vector<ll>>& a, vector<vector<ll>>& b) {
	vector<vector<ll>> c(sz, vector<ll>(sz, 0));
	loop(sz) {
		vloop(j, sz) {
			vloop(k, sz) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	return c;
}

vector<vector<ll>> xp(vector<vector<ll>>& b, int e) {
	if (e == 0) return {{1ll, 0ll}, {0ll, 1ll}};
	if (e == 1) return b;
	auto c = xp(b, e >> 1);
	c = c * c;
	if (e & 1) c = c * b;
	return c;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	vector<vector<ll>> mat = {{1, 1}, {1, 0}};
	for (int i = 1;i <= t;i++) {
		int n;
		cin >> n;
		auto c = xp(mat, n - 1);
		ll ans = 0;
		loop(2) vloop(j, 2) ans += c[i][j];
		cout << "Scenario #" << i << ":" << endl;
		cout << ans << endl << endl;
	}
	return 0;
}

