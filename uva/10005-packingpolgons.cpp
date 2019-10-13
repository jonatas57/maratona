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
	point operator+(point p) {
		return point(x + p.x, y + p.y);
	}
	point operator/(double a) {
		return point(x / a, y / a);
	}
};

double dist(point& p, point& q) {
	point del = p - q;
	return sqrt(del.x * del.x + del.y * del.y);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	while (cin >> n and n) {
		vector<point> ps;
		int x, y;
		double maxd = 0;
		point mid;
		loop(n) {
			cin >> x >> y;
			ps.emplace_back(x, y);
			mid = mid + ps[i];
		}
		mid = mid / n;
		double r;
		cin >> r;
		loop(n) {
			maxd = max(maxd, dist(mid, ps[i]));
		}
		cout << (maxd <= r ? "The polygon can be packed in the circle." : "There is no way of packing that polygon.") << endl;
	}
	return 0;
}

