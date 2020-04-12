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

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	vi a(n), b;
	loop(n) cin >> a[i];
	b = a;
	sort(b.begin(), b.end());
	vector<ii> ans;
	for (int i = 0;i < n;) {
		if (a[i] == b[i]) {
			i++;
			continue;
		}
		auto it = lower_bound(b.begin(), b.end(), a[i]);
		int j = it - b.begin();
		if (2 * abs(j - i) >= n) {
			ans.emplace_back(i, j);
		}
		else {
			int x = (i < n / 2 ? n - 1 : 0);
			ans.emplace_back(i, x);
			if (2 * abs(x - j) >= n) {
				ans.emplace_back(x, j);
			}
			else {
				int y = (x ? 0 : n - 1);
				ans.emplace_back(x, y);
				ans.emplace_back(y, j);
				ans.emplace_back(x, y);
			}
			ans.emplace_back(i, x);
		}
		swap(a[i], a[j]);
	}
	cout << ans.size() << endl;
	each(p, ans) {
		cout << p.first + 1 << " " << p.second + 1 << endl;
	}
	return 0;
}

