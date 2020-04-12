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
		if (i) cout << endl;
		int m, n;
		cin >> m >> n;
		vector<string> ss(m);
		loop(m) {
			cin >> ss[i];
			each(c, ss[i]) c = tolower(c);
		}
		int k;
		cin >> k;
		string s;
		loop(k) {
			cin >> s;
			each(c, s) c = tolower(c);
			int l = s.length();

			loop(m) vloop(j, n) {
				if (ss[i][j] != s[0]) continue;
				for (int delx = -1;delx <= 1;delx++) for (int dely = -1;dely <= 1;dely++) {
					if (!delx and !dely) continue;
					int id = 0;
					for (int x = i, y = j;x >= 0 and x < m and y >= 0 and y < n and id < l;x += delx, y += dely) {
						if (ss[x][y] == s[id]) {
							id++;
						}
						else {
							id = 0;
							break;
						}
					}
					if (id == l) {
						cout << i + 1 << " " << j + 1 << endl;
						i = m;
						j = n;
					}
				}
			}
		}
	}
	return 0;
}

