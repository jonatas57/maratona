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
	point(double x = 0, double y = 0) :x(x), y(y) {}
	point operator-(point p) {
		return point(x - p.x, y - p.y);
	}
};

struct line {
	double a, b, c;
	line(point& p, point& q) {
		point del = p - q;
		a = del.y;
		b = -del.x;
		c = -(a * p.x + b * p.y);
	}
	double operator()(int y) {
		return -(b * y + c) / a;
	}
};

double dist(point a, point b) {
	point p = b - a;
	return sqrt(p.x * p.x + p.y * p.y);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int c;
	cin >> c;
	loop(c) {
		vector<point> ps;
		int n, x, y;
		cin >> n;
		loop(n) {
			cin >> x >> y;
			ps.emplace_back(x, y);
		}
		sort(iter(ps), [](point p, point q) {
			return p.x > q.x;
		});
		double ans = 0, h = 0;
		for (int i = 0;i + 1 < n;i += 2) {
			if (ps[i + 1].y > h) {
				line l(ps[i], ps[i + 1]);
				ans += dist(point(l(h), h), ps[i + 1]);
				h = ps[i + 1].y;
			}
		}
		cout << fixed << setprecision(2) << ans << endl;
	}
	return 0;
}

