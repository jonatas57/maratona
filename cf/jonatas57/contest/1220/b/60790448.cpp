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
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	vector<vector<ll>> m(n, vector<ll>(n));
	loop(n) vloop(j, n) cin >> m[i][j];
	loop(n - 2) {
		ll x = m[i][i + 1] * m[i][i + 2] / m[i + 1][i + 2];
		cout << (ll)sqrt(x) << " ";
	}
	cout << (ll)sqrt(m[n - 2][n - 1] * m[n - 2][n - 3] / m[n - 3][n - 1]) << " ";
	cout << (ll)sqrt(m[n - 1][n - 2] * m[n - 1][n - 3] / m[n - 2][n - 3]) << " ";
	cout << endl;
	return 0;
}
