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
		int w, h, l, u, r, d;
		cin >> w >> h >> l >> u >> r >> d;
		vector<vector<double>> m(w, vector<double>(h, 0));
		l--, u--, r--, d--;
		m[0][0] = 1;
		loop(w) {
			vloop(j, h) {
				if (l <= i and i <= r and u <= j and j <= d) continue;
				if (i == w - 1 and j < h - 1) m[i][j + 1] += m[i][j];
				else if (j == h - 1 and i < w - 1) m[i + 1][j] += m[i][j];
				else if (i < w - 1 and j < h - 1) {
					m[i][j + 1] += m[i][j] / 2;
					m[i + 1][j] += m[i][j] / 2;
				}
			}
		}
		cout << "Case #" << i + 1 << ": " << fixed << setprecision(7) << m[w - 1][h - 1] << endl;
	}
	return 0;
}

