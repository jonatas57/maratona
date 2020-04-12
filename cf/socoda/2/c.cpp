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
	point(ll x = 0, ll y = 0) : x(x), y(y) {}
	point operator-(point& p) {
		return point(x - p.x, y - p.y);
	}
};

bool colinear(point p, point q, point r) {
	point u = q - p, v = r - p;
	return !(u.x * v.y - u.y * v.x);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	vector<point> ps;
	ll x, y;
	loop(n) {
		cin >> x >> y;
		ps.emplace_back(x, y);
	}
	bool p = true;
	if (n > 3) {
		vector<ii> ts = {{0, 1}, {0, 2}, {1, 2}};
		for (auto& [a, b] : ts) {
			p = true;
			vb used(n, false);
			used[a] = used[b] = true;
			for (int i = 0;i < n;i++) {
				if (used[i]) continue;
				if (colinear(ps[a], ps[b], ps[i])) used[i] = true;
			}
			int c = -1, d = -1;
			for (int i = 0;i < n and p;i++) {
				if (used[i]) continue;
				if (c == -1) c = i;
				else if (d == -1) d = i;
				else p = colinear(ps[c], ps[d], ps[i]);
			}
			if (p) break;
		}
	}
	cout << (p ? "YES" : "NO") << endl;
	return 0;
}

