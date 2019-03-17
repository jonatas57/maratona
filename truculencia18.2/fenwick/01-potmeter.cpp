#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define MAX                200010
#define N                  4 * MAX + 10
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define ceach(x, s)        for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2

struct bit {
	ll base[MAX], size;
	vector<ll> v;

	bit(vector<ll>& v) : size(v.size()), v(v) {
		memset(base, 0, sizeof base);
		loop(size) {
			update(i + 1, v[i], false);
		}
	}
	void update(ll a, ll val, bool p = true) {
		if (p) {
			val -= v[a - 1];
			v[a - 1] += val;
		}
		while (a <= size) {
			base[a] += val;
			a += a & (-a);
		}
	}
	ll query(ll x) {
		int ans = 0;
		while (x) {
			ans += base[x];
			x -= x & (-x);
		}
		return ans;
	}
	ll inter(ll l, ll r) {
		return query(r) - query(l - 1);
	}
};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, c = 0;
	while (cin >> n && n) {
		vector<ll> pot(n);
		loop(n) cin >> pot[i];
		bit ft(pot);
		string op;
		ll a, b;
		if (c) cout << "\n";
		cout << "Case " << ++c << ":\n";
		while (cin >> op && op != "END") {
			cin >> a >> b;
			if (op == "S") {
				ft.update(a, b);
			}
			else {
				cout << ft.inter(a, b) << "\n";
			}
		}
	}
	return 0;
}

