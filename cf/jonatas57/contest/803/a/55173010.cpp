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

	int n, k;
	cin >> n >> k;
	vector<vi> v(n, vi(n, 0));
	if (n * n >= k) {
		int aux = 0;
		while (k) {
			if (!v[aux][aux]) {
				v[aux][aux] = 1;
				k--;
			}
			if (k & 1 && aux < n) {
				v[aux + 1][aux + 1] = 1;
				k--;
			}
			int x = min(k / 2, n - aux - 1);
			loop(x) v[aux][aux + i + 1] = v[aux + i + 1][aux] = 1, k -= 2;
			aux++;
		}
		each(x, v) {
			each(y, x) cout << y << " ";
			cout << endl;
		}
	}
	else cout << -1 << endl;
	return 0;
}
