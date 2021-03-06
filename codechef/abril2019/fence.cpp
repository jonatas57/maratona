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

void fnc(bool& p, int& f) {
	if (p) f--;
	else f++;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		map<int, map<int, bool>> fs;
		int fence = 0;
		loop(k) {
			int x, y;
			cin >> x >> y;
			fs[x][y] = true;
			fnc(fs[x - 1][y], fence);
			fnc(fs[x][y - 1], fence);
			fnc(fs[x + 1][y], fence);
			fnc(fs[x][y + 1], fence);
		}
		cout << fence << endl;
	}
	return 0;
}

