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

struct point {
	ll x, y;
	point(ll x, ll y) : x(x), y(y) {}
};

struct line {
	ll a, b, c;
	line(point p, point q) {
		if (p.x == q.x) {
			a = 1;
			b = 0;
			c = -p.x;
		}
		else {
			a = q.y - p.y;
			b = p.x - q.x;
			c = -(a * p.x) - (p.y * b);
			ll m = __gcd(__gcd(a, b), c);
			a /= m;
			b /= m;
			c /= m;
			if (a < 0) {
				a = -a;
				b = -b;
				c = -c;
			}
		}
	}
	bool operator<(const line& l) const {
		return a == l.a ? (b == l.b ? c < l.c : b < l.b) : a < l.a;
	}
};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	int x, y;
	vector<point> ps;
	map<ll, map<ll, set<ll>>> ls;
	ll cnt = 0;
	loop(n) {
		cin >> x >> y;
		ps.emplace_back(x, y);
		for (int j = i - 1;j >= 0;j--) {
			line l(ps[i], ps[j]);
			if (ls[l.a][l.b].insert(l.c).second) cnt++;
		}
	}
	ll tot = (cnt * (cnt + 1)) / 2;
	for (auto& [a, m] : ls) {
		for (auto& [b, s] : m) {
			ll x = s.size();
			tot -= (x * (x + 1)) / 2;
		}
	}
	cout << tot << endl;
	return 0;
}
