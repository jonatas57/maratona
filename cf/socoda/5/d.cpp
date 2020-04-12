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
	ll x, y;
	point(ll x, ll y) : x(x), y(y) {}
	point operator-(point p) {
		return point(x - p.x, y - p.y);
	}
};

struct line {
	ll a, b, c;
	line(point p, point q) {
		point del = p - q;
		a = -del.y;
		b = del.x;
		c = -(a * p.x + b * p.y);
	}
	ll operator()(point p) {
		return abs(a * p.x + b * p.y + c);
	}
};

double dist(point p, line l) {
	return l(p) / sqrt(l.a * l.a + l.b * l.b);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	ll x, y;
	vector<point> ps;
	loop(n) {
		cin >> x >> y;
		ps.emplace_back(x, y);
	}
	ps.push_back(ps[0]);
	ps.push_back(ps[1]);
	double ans = INF;
	loop(n) {
		ans = min(ans, dist(ps[i + 1], line(ps[i], ps[i + 2])) / 2);
	}
	cout << fixed << setprecision(10) << ans << endl;
	return 0;
}

