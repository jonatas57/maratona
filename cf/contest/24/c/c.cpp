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
	point(ll x = 0, ll y = 0) : x(x), y(y) {}
	point operator-(point p) {
		return point(x - p.x, y - p.y);
	}
	point operator+(point p) {
		return point(x + p.x, y + p.x);
	}
	void operator+=(point p) {
		x += p.x;
		y += p.y;
	}
	point operator*(ll a) {
		return point(a * x, a * y);
	}
};

ostream& operator<<(ostream& os, point& p) {
	os << p.x << " " << p.y;
	return os;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	ll j;
	cin >> n >> j;
	vector<point> ps;
	ll x, y;
	cin >> x >> y;
	point m(x, y);
	loop(n) {
		cin >> x >> y;
		ps.emplace_back(x, y);
	}
	if (n & 1) {
		j %= 2 * n;
	}
	else {
		point v;
		loop(n) {
			v += (ps[i] - v) * 2;
		}
		m += v * (j / n);
		j %= n;
	}
	loop(j) {
		m += (ps[i % n] - m) * 2;
	}
	cout << m << endl;
	return 0;
}
