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
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

#define W 1
#define C 2
#define WC 3

struct zorc {
	int c, id;
	zorc(int c, int id) : c(c), id(id) {}
	bool operator<(const zorc& a) const {
		return c == a.c ? id < a.id : c < a.c;
	}
};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, m, a, b;
	cin >> n;
	vector<tuple<int, int, bool, int>> sl;
	loop(n) {
		cin >> a >> b;
		sl.emplace_back(a, b, false, i);
	}
	cin >> m;
	loop(m) {
		cin >> a >> b;
		sl.emplace_back(a, b, true, i + 1);
	}
	sort(iter(sl));
	vi ans(n, -1);
	int cnt = 0;
	bool pos = n <= m;
	set<zorc> zs;
	for (auto& [w, c, ax, id] : sl) {
		if (ax) {
			auto x = zs.upper_bound(zorc(c, INF));
			if (x != zs.begin()) {
				x = prev(x);
				cnt++;
				ans[x->id] = id;
				zs.erase(x);
			}
		}
		else {
			zs.emplace(c, id);
		}
	}
	if (cnt < n) pos = false;
	if (pos) {
		each(x, ans) cout << x << " ";
		cout << endl;
	}
	else cout << -1 << endl;
	return 0;
}

