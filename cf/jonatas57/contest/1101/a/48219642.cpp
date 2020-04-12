#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define each(x, s)         for(auto& x : s)
#define ceach(x, s)        for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define pb                 push_back

int main() {
	ios_base::sync_with_stdio(false);

	ll n, l, r, d, x;
	cin >> n;
	loop(n) {
		cin >> l >> r >> d;
		x = d;
		if (l <= d && d <= r) {
			x = r + (d - (r % d));
		}
		cout << x << endl;
	}
	return 0;
}
