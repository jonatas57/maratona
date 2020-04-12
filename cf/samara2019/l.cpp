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
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()

struct point {
	int x, y;
	point(int x = 0, int y = 0) : x(x), y(y) {}
};

double dist(point a, point b) {
	double delx = a.x - b.x, dely = a.y - b.y;
	return sqrt(delx * delx + dely * dely);
}

int main() {
	point c1, c2;
	int r1, r2;
	cin >> c1.x >> c1.y >> r1;
	cin >> c2.x >> c2.y >> r2;
	double d = dist(c1, c2);
	double ansr = (r1 + r2 - d) / 2;
	double d2 = r1 - ansr;
	point v(c2.x - c1.x, c2.y - c1.y);
	double cx = (double)(c1.x) + (v.x * d2 / d);
	double cy = (double)(c1.y) + (v.y * d2 / d);
	printf("%.10lf %.10lf %.10lf\n", cx, cy, ansr);
	return 0;
}
