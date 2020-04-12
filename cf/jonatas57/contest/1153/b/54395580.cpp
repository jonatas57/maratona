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

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, m, h;
	cin >> n >> m >> h;
	vi l(n), w(m);
	vector<vi> b(n, vi(m, 0));
	loop(m) cin >> w[i];
	loop(n) cin >> l[i];
	loop(n) vloop(j, m) {
		cin >> b[i][j];
		if (b[i][j]) b[i][j] = h;
	}
	loop(n) vloop(j, m) {
		if (b[i][j]) {
			b[i][j] = min(l[i], w[j]);
		}
	}
	each(x, b) {
		each(y, x) {
			cout << y << " ";
		}
		cout << endl;
	}
	return 0;
}

