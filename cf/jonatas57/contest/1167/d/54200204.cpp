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

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	string s;
	cin >> n >> s;
	int maxd = 0, d = 0;
	each(c, s) {
		if (c == '(') {
			d++;
			maxd = max(d, maxd);
		}
		else d--;
	}
	int x = maxd / 2;
	d = 0;
	each(c, s) {
		if (c == '(') {
			if (d < x) {
				d++;
				cout << 0;
			}
			else cout << 1;
		}
		else {
			if (d) {
				d--;
				cout << 0;
			}
			else cout << 1;
		}
	}	
	cout << endl;
	return 0;
}

