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
#define endl               "\n"

const double EPS = 1e-7;

struct point {
	double x, y;
	point(double x, double y) : x(x), y(y) {}
	point operator-(point p) {
		return point(x - p.x, y - p.y);
	}
	point operator+(point p) {
		return point(x + p.x, y + p.y);
	}
	point operator*(double u) {
		return point(u * x, u * y);
	}
};

double dot(point a, point b) {
	return a.x * b.x + a.y * b.y;
}
double sqnorm(point a) {
	return a.x * a.x + a.y * a.y;
}
double dist(point a, point b) {
	point del = b - a;
	return sqrt(del.x * del.x + del.y * del.y);
}

point nearLine(point p, point a, point b) {
	point ap = p - a, ab = b - a;
	double u = dot(ap, ab) / sqnorm(ab);
	if (u <= 0) return a;
	if (u >= 1) return b;
	return a + (ab * u);
}

int main() {
	double x, y;
	while (cin >> x >> y) {
		point m(x, y);
		vector<point> ps;
		int n;
		cin >> n;
		loop(n + 1) {
			cin >> x >> y;
			ps.emplace_back(x, y);
		}
		point ans(0, 0);
		double d = INF;
		loop(n) {
			point c = nearLine(m, ps[i], ps[i + 1]);
			double nd = dist(m, c);
			if (d > nd) {
				d = nd;
				ans = c;
			}
		}
		printf("%.4f\n%.4f\n", ans.x, ans.y);
	}
	return 0;
}

