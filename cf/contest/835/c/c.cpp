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

	int n, q, c;
	cin >> n >> q >> c;
	vector<vector<vi>> m(c + 1, vector<vi>(101, vi(101, 0)));
	int x, y, s;
	loop(n) {
		cin >> x >> y >> s;
		m[s][x][y]++;
	}
	vloop(k, c + 1) {
		for (int i = 1;i <= 100;i++) {
			for (int j = 1;j <= 100;j++) {
				m[k][i][j] += m[k][i][j - 1] + m[k][i - 1][j] - m[k][i - 1][j - 1];
			}
		}
	}
	int x2, y2, t;
	loop(q) {
		cin >> t >> x >> y >> x2 >> y2;
		t %= c + 1;
		x--, y--;
		int ans = 0;
		loop(c + 1) {
			ans += ((i + t) % (c + 1)) * (m[i][x2][y2] - m[i][x][y2] - m[i][x2][y] + m[i][x][y]);
		}
		cout << ans << endl;
	}
	return 0;
}

