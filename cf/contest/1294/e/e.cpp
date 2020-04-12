#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define INFLL              0x3f3f3f3f3f3f3f3f
#define each(x, s)         for(auto& x : s)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

const ll mod = 1000000007;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<vi> a(m, vi(n));
	loop(n) {
		vloop(j, m) {
			cin >> a[j][i];
			a[j][i]--;
		}
	}
	int ans = 0;
	loop(m) {
		mii cnt;
		vloop(j, n) {
			if (a[i][j] % m == i) {
				int y = a[i][j] / m;
				if (y >= n) continue;
				if (y > j) y -= n;
				cnt[j - y]++;
			}
		}
		int x = n;
		for (auto& [a, b] : cnt) {
			x = min(x, a + n - b);
		}
		ans += x;
	}
	cout << ans << endl;
	return 0;
}

