#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define MAX                10000010
#define N                  4 * MAX + 10
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define ceach(x, s)        for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2

struct bit {
	int *base, size;

	bit(int n) : size(n) {
		base = (int*)calloc(size + 1, sizeof(int));
	}
	void update(int a, int val) {
		while (a <= size) {
			base[a] += val;
			a += a & (-a);
		}
	}
	int query(int x) {
		int ans = 0;
		while (x) {
			ans += base[x];
			x -= x & (-x);
		}
		return ans;
	}
};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		int n, m = 0;;
		cin >> n;
		vi v(n);
		loop(n) cin >> v[i], m = max(m, v[i]);
		bit ft(m);
		ll ans = 0;
		for (int i = n;i > 0;i--) {
			ans += ft.query(v[i - 1] - 1);
			ft.update(v[i - 1], 1);
		}
		cout << ans << endl;
		free(ft.base);
	}
	return 0;
}

