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

	int m, n;
	while (cin >> n >> m and n | m) {
		int x;
		priority_queue<int, vi, greater<int>> k, h;
		loop(n) {
			cin >> x;
			h.push(x);
		}
		loop(m) {
			cin >> x;
			k.push(x);
		}
		int ans = 0, qk = m, qh = n;
		while (qk and qh) {
			if (k.top() >= h.top()) {
				ans += k.top();
				h.pop();
				qh--;
			}
			k.pop();
			qk--;
		}
		if (h.empty()) cout << ans << endl;
		else cout << "Loowater is doomed!" << endl;
	}
	return 0;
}

