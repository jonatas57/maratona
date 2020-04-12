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
int m, n, k, t, maxa;
vi a;
vector<tuple<int, int, int>> sl;

bool check(int mid) {
	int ti = 0, ts = 0, last = 0;
	vb used(n, false);
	for (auto& [x, id, d] : sl) {
		if (d < 0) {
			if (used[id]) ts--;
		}
		else if (d >= mid) {
			used[id] = true;
			ts++;
		}
		ti += (x - last) * (ts ? 3 : 1);
		if (d < 0 and !ts and used[id]) ti += 2;
		last = x;
	}
	ti += n - last;
	return ti > t;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	cin >> m >> n >> k >> t;
	a.resize(m);
	int l = 200000, r = 0; 
	loop(m) cin >> a[i], r = max(r, a[i]), l = min(l, a[i]);
	loop(k) {
		int x, y, z;
		cin >> x >> y >> z;
		sl.emplace_back(x, i, z);
		sl.emplace_back(y + 1, i, -z);
	}
	sort(iter(a));
	sort(iter(sl));
	l--;
	while (l < r) {
		int mid = avg(l, r);
		if (check(mid)) l = mid + 1;
		else r = mid;
	}
	int maxd = 0;
	for (auto& [x, id, d] : sl) {
		if (d < l) maxd = max(d, maxd);
	}
	cout << a.end() - lower_bound(iter(a), maxd) << endl;
	return 0;
}

