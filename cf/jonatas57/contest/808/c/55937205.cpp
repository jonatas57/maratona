#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define MAX                100000
#define N                  4 * MAX + 10
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define ceach(x, s)        for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2

struct cup {
	int v, f, id;
	cup(int v, int i) : v(v), f(0), id(i) {}
	bool operator<(cup& c) {
		return v < c.v;
	}
};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, w;
	cin >> n >> w;
	vector<cup> a;
	int x;
	loop(n) {
		cin >> x;
		a.emplace_back(x, i);
	}
	sort(a.begin(), a.end());
	loop(n) {
		a[i].f = (a[i].v + 1) / 2;
		w -= a[i].f;
	}
	for (int i = n - 1;i >= 0 && w > 0;i--) {
		int x = min(a[i].v - a[i].f, w);
		a[i].f += x;
		w -= x;
	}
	if (w < 0) cout << -1 << endl;
	else {
		sort(a.begin(), a.end(), [](cup& a, cup& b) { return a.id < b.id; } );
		each(x, a) cout << x.f << " ";cout << endl;
	}
	return 0;
}

