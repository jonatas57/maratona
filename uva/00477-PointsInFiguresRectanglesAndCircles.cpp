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
	double x, y;
	point(double x = 0, double y = 0) : x(x), y(y) {}
	point operator-(point& p) {
		return point(x - p.x, y - p.y);
	}
};

double dist(point p, point q) {
	point del = p - q;
	return sqrt(del.x * del.x + del.y * del.y);
}

struct figure {
	virtual bool inside(point& p) = 0;
};

struct rect : figure {
	double a, b, c, d;
	rect(double a, double b, double c, double d) : a(a), b(b), c(c), d(d) {}
	bool inside(point& p) {
		return a < p.x and p.x < b and c < p.y and p.y < d;
	}
};

struct circle : figure {
	point o;
	double r;
	circle(double x, double y, double r) : o(x, y), r(r) {}
	bool inside(point& p) override {
		return dist(p, o) < r;
	}
};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	char t;
	vector<figure*> fs;
	while (cin >> t and t != '*') {
		double a, b, c, d;
		if (t == 'r') {
			cin >> a >> b >> c >> d;
			fs.push_back((figure*)new rect(a, c, d, b));
		}
		else {
			cin >> a >> b >> c;
			fs.push_back((figure*)new circle(a, b, c));
		}
	}
	double x, y;
	int n = fs.size();
	for (int i = 1;cin >> x >> y and x < 9999.9 and y < 9999.9;i++) {
		point p(x, y);
		bool ins = false;
		vloop(j, n) {
			if (fs[j]->inside(p)) {
				ins = true;
				cout << "Point " << i << " is contained in figure " << j + 1 << endl;
			}
		}
		if (!ins) cout << "Point " << i << " is not contained in any figure" << endl;
	}
	return 0;
}

