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
	vector<tuple<int, bool, int, int>> sl;
	vector<ii> segs;
	cin >> n;
	int l, r;
	loop(n) {
		cin >> l >> r;
		sl.emplace_back(l, false, r, i);
		sl.emplace_back(r, true, -l, i);
		segs.emplace_back(l, r);
	}
	sort(iter(sl));
	vb used(n, false);
	priority_queue<ii, vector<ii>, greater<ii>> q;
	for (auto& [x, rig, l, id] : sl) {
		l = abs(l);
		if (rig) {
			used[id] = false;
			while (!q.empty() and !used[q.top().second]) q.pop();
			if (q.empty()) continue;
			auto t = q.top();
			if (t.first <= l) {
				cout << id + 1 << " " << t.second + 1 << endl;
				return 0;
			}
		}
		else {
			used[id] = true;
			q.emplace(x, id);
		}
	}
	cout << "-1 -1" << endl;
	return 0;
}

