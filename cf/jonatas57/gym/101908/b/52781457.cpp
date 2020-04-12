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

int board[101][101];
void init() {
	loop(101) vloop(j, 101) {
		if (i == 0 || j == 0 || i == j) {
			board[i][j] = INF;
		}
		else {
			vb x(300, false);
			vloop(k, j) if (board[i][k] != INF) x[board[i][k]] = true;
			vloop(k, i) if (board[k][j] != INF) x[board[k][j]] = true;
			int m = min(i, j);
			vloop(k, m) if (board[i - k - 1][j - k - 1] != INF) x[board[i - k - 1][j - k - 1]] = true;
			int p = 0;
			while (x[p]) p++;
			board[i][j] = p;
		}
	}
	board[0][0] = 0;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	init();
	int n;
	cin >> n;
	int ans = 0, x, y;
	bool p = false;
	loop(n) {
		cin >> x >> y;
		ans ^= board[x][y];	
		p |= board[x][y] == INF;
	}
	cout << (ans || p ? "Y\n" : "N\n");
	return 0;
}

