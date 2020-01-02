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

	int n, m, a, b, ans = 0;
	cin >> n >> m;
	vector<ii> sl;
	loop(n) {
		cin >> a >> b;
		sl.emplace_back(b, a);
	}
	sort(iter(sl), [](ii a, ii b) {
		return a.second == b.second ? a.first < b.first : a.second < b.second;
	});
	int at = 0;
	priority_queue<ii> q;
	loop(m + 1) {
		while (at < n and sl[at].second == i) q.push(sl[at++]);
		if (!q.empty()) {
			ans += q.top().first;
			q.pop();
		}
	}
	cout << ans << endl;
	return 0;
}

