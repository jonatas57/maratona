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

bool inside(int x, tuple<int, int, int> p) {
	int l, r;
	tie(r, l, ignore) = p;
	return x >= -l and x <= r;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	priority_queue<tuple<int, int, bool, int>> sl;
	int l, r;
	loop(n) {
		cin >> l >> r;
		sl.emplace(-l, r, false, i + 1);
		sl.emplace(-r, l, true, i + 1);
	}
	sl.emplace(-1, -1, false, 0);
	vi ans;
	bool pos = true, rem;
	int x, y, id, last = 0, lastActive = -1;
	priority_queue<tuple<int, int, int>> q;
	while (!sl.empty()) {
		if (!pos) break;
		tie(x, y, rem, id) = sl.top();
		sl.pop();
		x = -x;

		if (y == -1) {
			if (x > m) continue;
			if (q.empty() or not inside(x, q.top())) pos = false;
			else {
				int qx, qy, qid;
				tie(qy, qx, qid) = q.top();
				lastActive = qid;
				ans.push_back(qid);
				last = qy;
				sl.emplace(-(last + 1), -1, false, 0);
			}
		}
		else {
			if (rem) {
				if (id == lastActive) lastActive = -1;
			}
			else {
				q.emplace(y, -x, id);
			}
		}
	}
	if (pos) {
		cout << "YES" << endl << ans.size() << endl;
		each(x, ans) cout << x << " ";
		cout << endl;
	}
	else cout << "NO" << endl;
	return 0;
}
