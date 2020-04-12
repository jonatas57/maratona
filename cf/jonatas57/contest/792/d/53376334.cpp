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

ll n, q, root;

ll lsb(ll u) {
	return u & -u;
}
void left(ll& u) {
	if (u & 1) return;
	ll l = lsb(u);
	u -= l;
	l >>= 1;
	u += l;
}
void right(ll& u) {
	if (u & 1) return;
	ll l = lsb(u);
	u += (l >> 1);
}
void up(ll& u) {
	if (u == root) return;
	ll l = lsb(u);
	u -= l;
	ll m = lsb(u);
	if (m != (l << 1)) u += (l << 1);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	cin >> n >> q;
	root = (n + 1) >> 1;
	ll u;
	string s;
	loop(q) {
		cin >> u >> s;
		each(c, s) {
			if (c == 'L') {
				left(u);
			}
			else if (c == 'R') {
				right(u);
			}
			else {
				up(u);
			}
		}
		cout << u << endl;
	}
	return 0;
}
