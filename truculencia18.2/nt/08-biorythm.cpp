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

ii diof(int a, int b) {
	int s = 0, olds = 1;
	int t = 1, oldt = 0;
	int r = b, oldr = a;

	while (r) {
		int d = oldr / r;
		tie(oldr, r) = make_tuple(r, oldr - d * r);
		tie(olds, s) = make_tuple(s, olds - d * s);
		tie(oldt, t) = make_tuple(t, oldt - d * t);
	}
	return {olds, oldt};
}

int inv(int x, int m) {
	x %= m;
	int a, b;
	tie(a, b) = diof(x, m);
	if (a < 0) a += m;
	return a;
}

int chinese(vi r, vi m, int n) {
	int mod = 1;
	loop(n) mod *= m[i];
	vi M(n, mod);
	loop(n) M[i] /= m[i];
	vi in(n);
	loop(n) in[i] = inv(M[i], m[i]);
	int ans = 0;
	loop(n) ans += r[i] * M[i] * in[i];
	ans %= mod;
	if (ans < 0) ans += mod;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int p, e, i, d, c = 1;
	while (cin >> p >> e >> i >> d and p + e + i + d != -4) {
		int x = (d - p) % 23, y = (d - e) % 28, z = (d - i) % 33;
		int ans = 21252 - chinese({x, y, z}, {23, 28, 33}, 3);
		cout << "Case " << c++ << ": the next triple peak occurs in " << ans << " days.\n";
	}
	return 0;
}

