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

	int n, k;
	cin >> n >> k;
	vector<vi> a(50, vi(n, 0));
	loop(n) cin >> a[0][i];
	vector<vector<ii>> sl(50);
	loop(n) {
		sl[0].emplace_back(max(0, i - a[0][i]), 0);
		sl[0].emplace_back(min(n - 1, i + a[0][i]), 1);
	}
	int st = 0, t = 1;
	for (;st < n and t <= k;t++) {
		sort(iter(sl[t - 1]));
		st = 0;
		int x = 0;
		int id = 0;
		loop(n) {
			for (;id < n + n and (sl[t - 1][id].first < i or (sl[t - 1][id].first == i and !sl[t - 1][id].second));id++) {
				x += sl[t - 1][id].second ? -1 : 1;
			}
			a[t + 1][i] = x;
			if (a[t + 1][i] == n) st++;
			sl[t].emplace_back(max(0, i - a[t + 1][i]), 0);
			sl[t].emplace_back(min(n - 1, i + a[t + 1][i]), 1);
		}
	}
	each(x, a[t]) cout << x << " ";
	cout << endl;
	return 0;
}

