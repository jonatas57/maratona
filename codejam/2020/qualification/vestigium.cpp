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

	int t;
	cin >> t;
	loop(t) {
		int n;
		cin >> n;
		int m;
		vector<vb> rows(n, vb(n, false)), cols(n, vb(n, false));
		vb row(n, false), col(n, false);
		int sum = 0;
		loop(n) {
			vloop(j, n) {
				cin >> m;
				if (rows[i][m - 1]) row[i] = true;
				if (cols[j][m - 1]) col[j] = true;
				rows[i][m - 1] = true;
				cols[j][m - 1] = true;
				if (i == j) sum += m;
			}
		}
		int r = 0, c = 0;
		loop(n) {
			if (row[i]) r++;
			if (col[i]) c++;
		}
		cout << "Case #" << i + 1 << ": " << sum << " " << r << " " << c << endl;
	}
	return 0;
}

