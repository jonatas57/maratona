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

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	vector<tuple<int, bool, int>> sl;
	int l, r;
	loop(n) {
		cin >> l >> r;
		sl.emplace_back(l, false, i);
		sl.emplace_back(r, true, i);
	}
	sort(iter(sl));
	int size = sl.size();
	vb used(size, false);
	set<int> active;
	vi ans;
	for (auto& [x, rem, id] : sl) {
		if (rem) {
			if (!used[id]) {
				ans.push_back(x);
				each(y, active) used[y] = true;
				active.clear();
			}
			if (!active.empty()) active.erase(id);
		}
		else {
			active.insert(id);
		}
	}
	cout << ans.size() << endl;
	each(x, ans) cout << x << " ";
	cout << endl;
	return 0;
}

