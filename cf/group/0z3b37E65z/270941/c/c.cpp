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

	int n;
	cin >> n;
	int l, r;
	vector<tuple<int, int, int>> sl;
	vector<ii> evs;
	loop(n) {
		cin >> l >> r;
		sl.emplace_back(l, false, i);
		sl.emplace_back(r, true, i);
		evs.emplace_back(l, r);
	}
	sort(iter(sl));
	set<int> active;
	vb ans(1e7, false), ok(n, false);
	int ond = 0, last = -1, lastid = -1;
	for (auto& [x, rem, id] : sl) {
		if (rem) {
			if (active.count(id)) {
				active.erase(id);
				ond--;
			}
			if (ond == 1) {
				int y = *active.begin();
				for (int i = evs[y].first - 1;i < evs[y].second;i++) {
					if (!ans[i]) {
						ans[i] = ok[y] = true;
						break;
					}
				}
				active.clear();
				ond--;
			}
		}
		else {
			if (last != x and ond == 1) {
				int y = *active.begin();
				for (int i = evs[y].first - 1;i < evs[y].second;i++) {
					if (!ans[i]) {
						ans[i] = ok[y] = true;
						break;
					}
				}
				active.clear();
				ond--;
			}
			active.insert(id);
			ond++;
			last = x;
			lastid = id;
		}
	}
	sort(iter(evs));
	loop(n) {
		if (ok[i]) continue;
		for (int j = evs[i].first - 1;j < evs[i].second;j++) {
			if (!ans[j]) {
				ans[j] = true;
				break;
			}
		}
	}
	loop(1e7) {
		if (ans[i]) cout << i + 1 << " ";
	}
	cout << endl;
	return 0;
}

