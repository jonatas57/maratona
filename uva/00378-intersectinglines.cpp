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
	int a, b, c;
	line(point p, point q) {
		point del = p.y > q.y ? p - q : q - p;
		a = del.y;
		b = -del.x;
		c = -(a * p.x + b * p.y);
		int m = __gcd(__gcd(a, b), c);
		a /= m, b /= m, c /= m;
	}
};

bool parallel(line a, line b) {
	return a.a == b.a and a.b == b.b;
}

bool equal(line a, line b) {
	return parallel(a, b) and a.c == b.c;
}

istream& operator>>(istream& is, point &p) {
	is >> p.x >> p.y;
	return is;
}

const double EPS = 1e-4;
point intersect(line r, line s) {
	point p(s.b * r.c - s.c * r.b, 0);
	p.x /= (s.a * r.b - s.b * r.a);
	if (abs(s.b) < EPS) p.y = -(r.a * p.x + r.c) / r.b;
	else p.y = -(s.a * p.x + s.c) / s.b;
	if (abs(p.x) < EPS) p.x = 0;
	if (abs(p.y) < EPS) p.y = 0;
	return p;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	cout << "INTERSECTING LINES OUTPUT" << endl;
	loop(t) {
		point a, b, c, d;
		cin >> a >> b >> c >> d;
		line r(a, b), s(c, d);
		if (equal(r, s)) cout << "LINE" << endl;
		else if (parallel(r, s)) cout << "NONE" << endl;
		else {
			point p = intersect(r, s);
			cout << "POINT ";
			cout << fixed << setprecision(2) << p.x << " " << p.y << endl;
		}
	}
	cout << "END OF OUTPUT" << endl;
	return 0;
}

