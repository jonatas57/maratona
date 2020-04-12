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

	int n, m, s;
	map<char, int> dirs = {{'N', 0}, {'L', 1}, {'S', 2}, {'O', 3}};
	while (cin >> n >> m >> s and n | m | s) {
		vector<string> area(n);
		int x, y, dir;
		loop(n) {
			cin >> area[i];
			vloop(j, m) {
				if (isalpha(area[i][j])) {
					x = i;
					y = j;
					dir = dirs[area[i][j]];
				}
			}
		}
		string ins;
		cin >> ins;
		int ans = 0;
		each(c, ins) {
			if (c == 'D') {
				dir++;
				if (dir == 4) dir = 0;
			}
			else if (c == 'E') {
				dir--;
				if (dir == -1) dir = 3;
			}
			else {
				int nx = x + (dir == 2) - (dir == 0);
				int ny = y + (dir == 1) - (dir == 3);
				if (nx < 0 or nx == n or ny < 0 or ny == m or area[nx][ny] == '#') continue;
				x = nx, y = ny;
				if (area[x][y] == '*') {
					area[x][y] = '.';
					ans++;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}

