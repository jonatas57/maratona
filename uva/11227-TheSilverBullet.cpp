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
		return point(x - p.x, y - p.y);
	}
	bool operator<(const point& p) const {
		return x == p.x ? y < p.y : x < p.x;
	}
};

struct line {
	int a, b, c;
	line(point p, point q) {
		point del = p - q;
		a = del.y;
		b = -del.x;
		int m = __gcd(abs(a), abs(b));
		a /= m;
		b /= m;
		if (a < 0) a = -a, b = -b;
		c = -(a * p.x + b * p.y);
	}
	bool operator<(const line& l) const {
		return a == l.a ? (b == l.b ? c < l.c : b < l.b) : a < l.a;
	}
};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		int n;
		cin >> n;
		set<point> ps;
		int a, b, c, d;
		char x;
		loop(n) {
			cin >> a >> x >> b >> c >> x >> d;
			ps.emplace(a * 100 + b, c * 100 + d);
		}
		n = ps.size();
		if (n == 1) {
			cout << "Data set #" << i + 1 << " contains a single gnu." << endl;
		}
		else {
			int m = 0;
			for (auto i = ps.begin();i != ps.end();i++) {
				map<line, int> cnt;
				auto j = i;
				j++;
				for (;j != ps.end();j++) {
					line l(*i, *j);
					cnt[l]++;
				}
				each(p, cnt) m = max(m, p.second + 1);
			}
			cout << "Data set #" << i + 1 << " contains " << n << " gnus, out of which a maximum of " << m << " are aligned." << endl;
		}
	}
	return 0;
}

