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

	int w, h;
	cin >> w >> h;
	int x, y;
	char d;
	string ds = "NESW";
	vector<vb> edge(w + 1, vb(h + 1, false));
	while (cin >> x >> y >> d) {
		string s;
		cin >> s;
		int dir;
		loop(4) if (d == ds[i]) dir = i;
		bool fall = false;
		each(c, s) {
			if (c == 'L') {
				dir--;
				if (dir < 0) dir = 3;
			}
			else if (c == 'R') {
				dir++;
				if (dir > 3) dir = 0;
			}
			else {
				int nx = x + (dir == 1) - (dir == 3);
				int ny = y + (dir == 0) - (dir == 2);
				if (nx < 0 or ny < 0 or nx > w or ny > h) {
					if (!edge[x][y]) {
						edge[x][y] = fall = true;
						cout << x << " " << y << " " << ds[dir] << " LOST" << endl;
						break;
					}
				}
				else x = nx, y = ny;
			}
		}
		if (!fall) cout << x << " " << y << " " << ds[dir] << endl;
	}
	return 0;
}

