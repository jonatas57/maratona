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

	int n, m;
	for (int t = 1;cin >> n >> m and n | m;t++) {
		vector<string> ss(n);
		loop(n) {
			cin >> ss[i];
			vloop(j, m) {
				if (ss[i][j] == '.') ss[i][j] = '0';
			}
		}
		loop(n) {
			vloop(j, m) {
				if (ss[i][j] == '*') {
					for (int x = i - 1;x <= i + 1;x++) {
						for (int y = j - 1;y <= j + 1;y++) {
							if (x < 0 or y < 0 or x >= n or y >= m or ss[x][y] == '*') continue;
							ss[x][y]++;
						}
					}
				}
			}
		}
		if (t > 1) cout << endl;
		cout << "Field #" << t << ":" << endl;
		each(s, ss) cout << s << endl;
	}
	return 0;
}

