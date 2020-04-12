#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define loop(x) for (int i = 0;i < x;i++)
#define each(x, xs) for (auto& x : xs)
#define iter(a) a.begin(), a.end()

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const double EPS = 1e-8;

struct point {
    double x, y;
    point(double a = 0, double b = 0) : x(a), y(b) {
	if (abs(x) < EPS) x = 0;
	if (abs(y) < EPS) y = 0;
    }
    point operator-(point& p) {
	return point(x - p.x, y - p.y);
    }
};

double cross(point p, point q) {
    return p.x * q.y - p.y * q.x;
}

double dot(point& p, point& q) {
    return p.x * q.x + p.y * q.y;
}

double normsq(point& p) {
    return p.x * p.x + p.y * p.y;
}

double ccw(point& p, point& q, point& r) {
    return cross(q - p, r - p) > 0;
}

double angle(point& a, point& o, point b) {
    auto oa = a - o, ob = b - o;
    return acos(dot(oa, ob) / sqrt(normsq(oa) * normsq(ob)));
}

struct polygon {
    int size;
    vector<point> ps;
    polygon(int s, point p) : size(s) {
	complex<double> w(p.x, p.y), ang(cos(2 * PI / s), sin(2 * PI / s));
	loop(s) {
	    ps.emplace_back(w.real(), w.imag());
	    w *= ang;
	}
	ps.push_back(ps[0]);
    }
    double area() {
	double a = 0;
	loop(size) {
	    a += cross(ps[i], ps[i + 1]);
	}
	return abs(a) / 2;
    }
    bool inside(point& p) {
	double sum = 0;
	loop(size) {
	    double ang = angle(ps[i], p, ps[i + 1]);
	    sum += ccw(p, ps[i], ps[i + 1]) ? ang : -ang;
	}
	return abs(abs(sum) - 2 * PI) < EPS;
    }
};

vector<point> ps;

bool check(polygon& pol, bool m) {
    each(p, ps) {
	bool ins = pol.inside(p);
	if (m ^ ins) return false;
    }
    return true;
}

polygon bb(double l, double r, int k, bool m) {
    polygon ans(1, point(0, 0));
    while (abs(l - r) >= EPS) {
	double mid = (l + r) / 2;
	ans = polygon(k, point(mid, 0));
	bool x = check(ans, m);
	if (x) {
	    m ? r = mid : l = mid;
	}
	else {
	    m ? l = mid : r = mid;
	}
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    
    int n;
    cin >> n;
    int x, y;
    loop(n) {
	cin >> x >> y;
	ps.eb(x, y);
    }
    double ans = 0;
    int k;
    for (int i = 3;i <= 8;i++) {
	polygon inner = bb(0, INF, i, 0), outer = bb(0, INF, i, 1);
	double x = inner.area() / outer.area();
	if (ans < x) {
	    ans = x;
	    k = i;
	}
    }
    cout << k << " " << fixed << setprecision(6) << ans << endl;
}

