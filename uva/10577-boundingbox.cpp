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

struct point {
	double x, y;
	point(double x = 0, double y = 0) : x(x), y(y) {}
	point operator-(point p) {
		return point(x - p.x, y - p.y);
	}
};

struct line {
	double a, b, c;
	line(point p, point q) {
		point del = p - q;
		a = del.y;
		b = -del.x;
		c = -(a * p.x + b * p.y);
	}
	line(line l, point q) {
		a = -l.b;
		b = l.a;
		c = -(a * q.x + b * q.y);
	}
}

point midpoint(point p, point q) {
	return point(avg(p.x, q.x), avg(p.y, q.y));
}



int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	while (cin >> n and n) {
		point a, b, c;
		cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;

	}
	return 0;
}

