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
	vector<ii> ps;
	int a, b;
	loop(n) {
		cin >> a >> b;
		ps.emplace_back(a, b);
	}
	sort(iter(ps));
	int ans = 0;
	priority_queue<int> q;
	for (int i = 1, j = 0;i <= m and (j < n or !q.empty());i++) {
		while (j < n and ps[j].first <= i) q.push(ps[j].second), j++;
		if (!q.empty()) {
			ans += q.top();
			q.pop();
		}
	}
	cout << ans << endl;
	return 0;
}

