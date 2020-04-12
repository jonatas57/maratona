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
	int a, b, c, d, x, y, x1, x2, y1, y2;
	loop(t) {
		cin >> a >> b >> c >> d;
		cin >> x >> y >> x1 >> y1 >> x2 >> y2;
		int xf = x - a + b;
		int yf = y - c + d;
		bool p = x1 <= xf and xf <= x2 and y1 <= yf and yf <= y2;
		if (a | b and x1 == x2 and x == x1) p = false;
		if (c | d and y1 == y2 and y == y1) p = false;
		cout << (p ? "Yes" : "No") << endl;
	}
	return 0;
}

