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

	int t;
	cin >> t;
	while (t--) {
		int n;
		string s;
		char x;
		cin >> n >> s >> x;
		vi pos;
		loop(n) {
			if (s[i] == x) {
				pos.push_back(i);
			}
		}
		ll ans = 0;
		if (pos.size()) {
			int first = pos.front(), last = pos.back(), j = 0;
			each(c, s) {
				ans += n - first;
				if (c == x) {
					if (last == first) break;
					first = pos[++j];
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}

