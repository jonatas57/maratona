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
const double EPS = 1e-7;

struct rect {
	int id;
	double l, u, r, d;
	rect(double l, double u, double r, double d, int id) : id(id), l(l), u(u), r(r), d(d) {}
	bool inside(double x, double y) {
		return l < x and x < r and d < y and y < u;
	}
};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	char t;
	double l, u, r, d;
	vector<rect> rs;
	for (int i = 1;cin >> t and t != '*';i++) {
		cin >> l >> u >> r >> d;
		rs.emplace_back(l, u, r, d, i);
	}
	double x, y;
	for (int i = 1;cin >> x >> y and (abs(x - 9999.9) > EPS or abs(y - 9999.9) > EPS);i++) {
		bool p = true;
		each(r, rs) {
			if (r.inside(x, y)) cout << "Point " << i << " is contained in figure " << r.id << endl, p = false;
		}
		if (p) cout << "Point " << i << " is not contained in any figure" << endl;
	}
	return 0;
}

