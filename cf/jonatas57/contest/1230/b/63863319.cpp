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

	int n, k;
	string s;
	cin >> n >> k >> s;
	if (n == 1 and k == 1) {
		cout << 0 << endl;
	}
	else {
		for (int i = 0;k and i < n;i++) {
			if (i and s[i] != '0') {
				s[i] = '0';
				k--;
			}
			else if (!i and s[i] != '1') {
				s[i] = '1';
				k--;
			}
		}
		cout << s << endl;
	}
	return 0;
}

