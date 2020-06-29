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

struct point {
	double x, y;
	point(double x = 0, double y = 0) : x(x), y(y) {}
	point operator-(point& p) {
		return point(x - p.x, y - p.y);
	}
};

double dist(point& p, point& q) {
	point del = p - q;
	return sqrt(del.x * del.x + del.y * del.y);
}

int main() {
	int n;
	while (cin >> n) {
		double a, b, c, d;
		cin >> a >> b >> c >> d;
		point p(a, b), q(c, d), ans;
		bool found = false;
		loop(n) {
			cin >> a >> b;
			point x(a, b);
			if (dist(q, x) >= 2 * dist(p, x)) {
				found = true;
				ans = x;
			}
		}
		if (found) printf("The gopher can escape through the hole at (%.3f,%.3f).\n", ans.x, ans.y);
		else cout << "The gopher cannot escape." << endl;
	}
	return 0;
}

