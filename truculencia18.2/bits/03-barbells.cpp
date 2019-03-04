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

set<int> sums(vi& v, int n) {
	map<int, list<int>> masks;
	int sum, x = 1 << n;
	set<int> ans;
	vloop(mask, x) {
		sum = 0;
		loop(n) {
			if (mask & (1 << i)) {
				sum += v[i];
			}
		}
		each(y, masks[sum]) {
			if (!(mask & y)) {
				ans.insert(2 * sum);
			}
		}
		masks[sum].push_front(mask);
	}
	return ans;
}


int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vi bar(n), dis(m);
	loop(n) cin >> bar[i];
	loop(m) cin >> dis[i];
	set<int> s = sums(dis, m), ans(bar.begin(), bar.end());
	each(x, bar) {
		each(y, s) {
			ans.insert(x + y);
		}
	}
	each(x, ans) {
		cout << x << endl;
	}
	return 0;
}
