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
	int x, y;
	point(int x, int y) :x(x), y(y) {}
	point operator-(point p) {
		return point(x - p.x, y - p.y);
	}
};

struct circle {
	point o;
	int r;
	circle(int x, int y, int r) : o(x, y), r(r) {}
};

double dist(point a, point b) {
	point del = a - b;
	return sqrt(del.x * del.x + del.y * del.y);
}

bool inter(circle c, circle d) {
	if (c.r > d.r) swap(c, d);
	double dt = dist(c.o, d.o);
	return dt < c.r + d.r and dt + c.r > d.r;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int x, y, r, R;
	vector<circle> cs[2];
	loop(2) {
		cin >> x >> y >> r >> R;
		cs[i].emplace_back(x, y, r);
		cs[i].emplace_back(x, y, R);
	}
	vb cnt(4, true);
	loop(2) {
		vloop(j, 2) {
			if (inter(cs[0][i], cs[1][j])) cnt[i] = cnt[2 + j] = false;
		}
	}
	loop(4) {
		int t = i >> 1, j = t & 1, r = t ^ 1;
		double d = dist(cs[t][j].o, cs[r][j].o);
		if (d - cs[t][j].r > cs[r][0].r and d + cs[t][j].r < cs[r][1].r) cnt[i] = false;
	}
	int ans = 0;
	loop(4) ans += cnt[i];
	cout << ans << endl;
	return 0;
}
