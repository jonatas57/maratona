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

int lsb(int x) {
	return x & -x;
}
int count(int x) {
	int c = 0;
	while (x) {
		x -= lsb(x);
		c++;
	}
	return c;
}
int heavy(vi& v, int n, int s) {
	int ans = 0, lim = 1 << n, sum;
	vloop(mask, lim) {
		sum = 0;
		for (int i = 0;i < n;i++) {
			if (mask & (1 << i)) {
				sum += v[i];
			}
		}
		int l = lsb(mask), x = sum - v[(int)log2(l)], c = count(mask);
		if (sum >= s && x < s && ans < c) {
			ans = c;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		int n, s;
		cin >> n >> s;
		vi p(n);
		loop(n) {
			cin >> p[i];
		}
		sort(p.begin(), p.end());
		int ans = heavy(p, n, s);
		cout << ans << endl;
	}
	return 0;
}
