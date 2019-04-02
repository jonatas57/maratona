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

struct bit2d {
	vector<vi> base, v;
	int size;

	bit2d(int n) : size(n) {
		base.resize(n + 1);
		v.resize(n + 1);
		loop(n + 1) {
			base[i].resize(n + 1, 0);
			v[i].resize(n + 1, 0);
		}
	}
	void update(int i, int j, int x) {
		int val = x - v[i][j];
		v[i][j] = x;
		int j1 = j;
		while (i <= size) {
			j = j1;
			while (j <= size) {
				base[i][j] += val;
				j += j & -j;
			}
			i += i & -i;
		}
	}
	int query(int x, int y) {
		int ans = 0;
		for (int i = x;i;i -= i & -i) {
			for (int j = y;j;j -= j & -j) {
				ans += base[i][j];
			}
		}
		return ans;
	}
	int inter(int a, int b, int c, int d) {
		return query(a - 1, b - 1) + query(c, d) - query(a - 1, d) - query(c, b - 1);
	}
};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	scanf("%d\n", &t);
	while (t--) {
		int n;
		scanf("%d\n", &n);
		bit2d bits(n);
		char op[4];
		int a, b, c, d;
		while (scanf("%s", op) != EOF && strcmp(op, "END")) {
			scanf("%d %d %d", &a, &b, &c);
			if (strcmp(op, "SET") == 0) {
				bits.update(a + 1, b + 1, c);
			}
			else {
				scanf("%d\n", &d);
				int ans = bits.inter(a + 1, b + 1, c + 1, d + 1);
				printf("%d\n", ans);
			}
		}
	}
	return 0;
}
