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

	int t;
	cin >> t;
	loop(t) {
		int n, x, y;
		vector<ii> ps;
		cin >> n;
		loop(n) {
			cin >> x >> y;
			ps.emplace_back(x, y);
		}
		sort(iter(ps));
		bool p = true;
		for (int i = 1;i < n and p;i++) {
			p &= ps[i].second >= ps[i - 1].second;
		}
		if (p) {
			cout << "YES" << endl;
			int x = 0, y = 0;
			for (auto [a, b] : ps) {
				cout << string(a - x, 'R') << string(b - y, 'U');
				x = a;
				y = b;
			}
			cout << endl;
		}
		else cout << "NO" << endl;
	}
	return 0;
}

