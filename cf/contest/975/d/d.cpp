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
	point operator-(point& p) {
		return point(x - p.x, y - p.y);
	}
	bool operator<(point& p) {
		return x == p.x ? y < p.y : x < p.x;
	}
};

const double EPS = 1e-9;

bool ismultiple(point p, point q) {
	if (q < p) swap(p.x, q.x), swap(p.y, q.y);
	return abs((double)q.x / p.x - (double)q.y / p.y) < EPS;
}

struct line {
	ll a, b;
	line(ll a, ll b) : a(a), b(b) {}
	ll operator()(ll x) {
		return a * x + b;
	}
};

struct ghost {
	point pos, vel;
	ghost(point pos, point vel) : pos(pos), vel(vel) {}
};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	ll n, a, b;
	cin >> n >> a >> b;
	line f(a, b);
	vector<ghost> gs;
	ll xp = 0;
	ll x, vx, vy;
	loop(n) {
		cin >> x >> vx >> vy;
		gs.emplace_back(point(x, f(x)), point(vx, vy));
		for (int j = 0;j < i;j++) {
			if (ismultiple(gs[i].pos - gs[j].pos, gs[j].vel - gs[i].vel)) {
				xp += 2;
			}
		}
	}
	cout << xp << endl;
	return 0;
}
