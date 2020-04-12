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
	int x, y;
	point(int x, int y) : x(x), y(y) {}
	point operator-(point& p) {
		return point(x - p.x, y - p,y);
	}
};

struct line {
	int a, b, c;
	int x1, x2;
	line(point p, point q) {
		point del = p - q;
		a = -del.y;
		b = del.x;
		c = -(a * p.x + b * p.y);
		x1 = p.x;
		x2 = q.x;
		if (x1 > x2) swap(x1, x2);
	}
	bool operator()(int x, int y) {
		return a * x + b * y == c;
	}
};

bool onLine(point p, line l) {
	return l(p.x, p.y) and p.x <= x2 and p.x >= x1;
}

bool cross(line r, line s)

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	
	return 0;
}

