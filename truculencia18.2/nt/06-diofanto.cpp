#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define MAX                1000000
#define N                  4 * MAX + 10
#define MOD                1300031
#define each(x, s)         for(auto& x : s)
#define ceach(x, s)        for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2

struct rat {
	ll a, b;
	rat(ll a, ll b) : a(a), b(b) {}
	ll getans() {
		if (a == 0 or b == 1) return a;
		rep(1, MOD, 1) if ((b * i) % MOD == a) return i;
	}
	void operator*=(ll x) {
		a *= x;
		if (a >= MOD) a %= MOD;
	}
	void operator/=(ll x) {
		b *= x;
		if (b >= MOD) b %= MOD;
	}
};

int mods[MOD];

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	ll t, n, c;
	cin >> t;
	loop(t) {
		cin >> n >> c;
		n--;
		if (n > c) swap(n, c);
		rat ans(1, 1);
		loop(n) {
			ans *= c + i + 1;
			ans /= i + 1;
			if (ans.a == 0) break;
		}
		cout << ans.getans() << endl;
	}
	return 0;
}

