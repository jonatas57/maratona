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
	ll x, y;
	point(int x, int y) : x(x), y(y) {}
};

ll cross(point p, point q) {
	return p.x * q.y - p.y * q.x;
}

double area(vector<point>& ps) {
	int l = ps.size();
	ll area = 0;
	loop(l) {
		area += cross(ps[i], ps[(i + 1) % l]);
	}
	return 0.5 * abs(area);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, m, x, y;
	cin >> n >> m;
	vector<point> ps;
	loop(n) {
		cin >> x >> y;
		ps.emplace_back(x, y);
	}
	ps.push_back(ps[0]);
	vector<ll> shoelace(n + 1, 0);
	for (int i = 1;i <= n;i++) {
		shoelace[i] = shoelace[i - 1] + cross(ps[i - 1], ps[i]);
	}
	double total = 0.5 * abs(shoelace[n]);
	double ans = 0;
	loop(m) {
		cin >> x >> y;
		x--, y--;
		if (x > y) swap(x,y);
		double area = 0.5 * abs(shoelace[y] - shoelace[x] + cross(ps[y], ps[x]));
		area = min(area, total - area);
		if (ans < area) ans = area;
	}
	cout << fixed << setprecision(6) << ans << endl;
	return 0;
}

