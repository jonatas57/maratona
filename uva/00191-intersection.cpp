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
#define iter(a)            a.begin(), a.end()

struct point {
	double x, y;
	point(double x = 0, double y = 0) : x(x), y(y) {}
	point operator-(point p) {
		return point(x - p.x, y - p.y);
	}
};

double cross(point a, point b) {
	return a.x * b.y - a.y * b.x;
}

int ccw(point a, point b, point c) {
	double cr = cross(b - a, c - a);
	return cr ? (cr > 0 ? 1 : -1) : 0;
}

double dot(point a, point b) {
	return a.x * b.x + a.y + b.y;
}
double sqnorm(point a) {
	return a.x * a.x + a.y * a.y;
}

bool onSegment(point p, point q, point r) {
	return q.x <= max(p.x, r.x) and q.x >= min(p.x, p.y) and q.y <= max(p.y, r.y) and q.y >= min(p.y, q.y);
}

bool intersect(point a, point b, point p, point q) {
    int c1 = ccw(a, b, p), c2 = ccw(a, b, q), c3= ccw(p, q, a), c4  = ccw(p, q, b);
    if (c1 != c2 and c3 != c4) return true;
    if (c1 == 0 and onSegment(a, b, p)) return true;
    if (c2 == 0 and onSegment(a, b, q)) return true;
    if (c3 == 0 and onSegment(p, q, a)) return true;
    if (c4 == 0 and onSegment(p, q, b)) return true;
    return false;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	string ans = "FT";
	cin >> n;
	loop(n) {
		int x1, x2, y1, y2;
		point a, b;
		cin >> a.x >> a.y >> b.x >> b.y >> x1 >> y1 >> x2 >> y2;
		bool p = intersect(a, b, point(x1, y1), point(x1, y2)) or intersect(a, b, point(x1, y2), point(x2, y2)) or intersect(a, b, point(x2, y1), point(x1, y1)) or intersect(a, b, point(x2, y2), point(x2, y1));
		cout << ans[p] << endl;
	}
	return 0;
}

