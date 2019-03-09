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
#define rep(x, y, z)       for(int i = x;i <= y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define pb                 push_back
#define avg(x, y)          x + (y - x) / 2

int mdc(int a, int b) {
	if (a == 0) return b;
	if (b == 0) return a;
	return mdc(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	int t;
	cin >> t;
	loop(t) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int x = 0;
		if (a != c or b != d) {
			x = mdc(abs(c - a), abs(d - b));
		}
		x++;
		cout << x << endl;
	}
	return 0;
}
