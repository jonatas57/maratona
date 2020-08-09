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
	vector<string> s(n);
	loop(n) cin >> s[i];
	vector<vi> ul(n, vi(m)), rd(n, vi(m)), ur(n, vi(m)), ld(n, vi(m));
	for (int i = 0, i2 = n - 1;i < n;i++, i2--) {
		for (int j = 0, j2 = m - 1;j < m;j++, j2--) {
			ul[i][j] = min(i and s[i - 1][j] == s[i][j] ? ul[i - 1][j] : 0, j and s[i][j - 1] == s[i][j]? ul[i][j - 1] : 0) + 1;
			rd[i2][j2] = min(i2 < n - 1 and s[i2 + 1][j2] == s[i2][j2] ? rd[i2 + 1][j2] : 0, j2 < m - 1 and s[i2][j2 + 1] == s[i2][j2] ? rd[i2][j2 + 1] : 0) + 1;
			ur[i][j2] = min(i and s[i - 1][j2] == s[i][j2] ? ur[i - 1][j2] : 0, j2 < m - 1 and s[i][j2 + 1] == s[i][j2]? ur[i][j2 + 1] : 0) + 1;
			ld[i2][j] = min(i2 < n - 1 and s[i2 + 1][j] == s[i2][j] ? ld[i2 + 1][j] : 0, j and s[i2][j - 1] == s[i2][j] ? ld[i2][j - 1] : 0) + 1;
		}
	}
	ll ans = 0;
	loop(n) {
		vloop(j, m) {
			ll y = min({ul[i][j], rd[i][j], ld[i][j], ur[i][j]});
			ans += y;
		}
	}
	cout << ans << endl;
	return 0;
}

