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
	int x, y, id;
	point(int x, int y, int id) : x(x), y(y), id(id) {}
};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	vector<point> ps;
	int x, y;
	loop(n) {
		cin >> x >> y;
		ps.emplace_back(x, y, i);
	}
	vi a(n, 0);
	sort(iter(ps), [](point p, point q) {
		return p.x == q.x ? p.y < q.y : p.x < q.x;
	});
	for (int i = 1;i < n;i++) if (ps[i].x == ps[i - 1].x) a[ps[i].id] |= 1, a[ps[i - 1].id] |= 2;
	sort(iter(ps), [](point p, point q) {
		return p.y == q.y ? p.x < q.x : p.y < q.y;
	});
	for (int i = 1;i < n;i++) if (ps[i].y == ps[i - 1].y) a[ps[i].id] |= 4, a[ps[i - 1].id] |= 8;
	int ans = 0;
	each(x, a) {
		if (x == 15) ans++;
	}
	cout << ans << endl;
	return 0;
}

