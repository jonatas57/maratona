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
const double EPS = 1e-6;

struct point {
	double x, y;
	point(double x = 0, double y = 0) : x(abs(x) > EPS ? x : 0), y(abs(y) > EPS ? y : 0) {}
	point operator-(point& p) {
		return point(x - p.x, y - p.y);
	}
};

struct line {
	double a, b, c;
	line(line& s, point m) {
		a = s.b;
		b = -s.a;
		c = -(a * m.x + b * m.y);
	}
	line(point p, point q) {
		point del = p - q;
		a = del.y;
		b = -del.x;
		c = -(a * p.x + b * p.y);
	}
};

point med(point a, point b) {
	return point((a.x + b.x) / 2, (a.y + b.y) / 2);
}

point cross(line& s, line& t) {
	double d = s.a * t.b - s.b * t.a;
	return point((s.b * t.c - s.c * t.b) / d, (s.c * t.a - t.c * s.a) / d);
}

double dist(point p, point q) {
	point del = p - q;
	return sqrt(del.x * del.x + del.y * del.y);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	point a, b, c;
	while (cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y) {
		line s(a, b), t(b, c);
		line sp(s, med(a, b)), tp(t, med(b, c));
		point o = cross(sp, tp);
		cout << fixed << setprecision(2) << 2 * dist(o, a) * acos(-1) << endl;
	}
	return 0;
}

