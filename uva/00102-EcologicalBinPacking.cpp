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

	int a[3][3];
	while (cin >> a[0][0]) {
		int sum = a[0][0];
		loop(3) {
			vloop(j, 3) {
				if (i == 0 and j == 0) continue;
				cin >> a[i][j];
				sum += a[i][j];
			}
		}
		int ans = INT_MAX;
		string s = "ZZZ", aux = "BGC";
		loop(3) {
			vloop(j, 3) {
				vloop(k, 3) {
					if (i == j or j == k or i == k) continue;
					int x;
					if (ans >= (x = sum - a[0][i] - a[1][j] - a[2][k])) {
						string t = "";
						t += aux[i];
						t += aux[j];
						t += aux[k];
						if (ans == x) s = min(s, t);
						else s = t;
						ans = x;
					}
				}
			}
		}
		cout << s << " " << ans << endl;
	}
	return 0;
}

