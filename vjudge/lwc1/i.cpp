#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<ll, ll>     ii;

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
		ll n, x;
		cin >> n >> x;
		vector<ii> ps;
		ps.emplace_back(0, -1);
		ll last = 0, a;
		loop(n) {
			cin >> a;
			a += last;
			last = a;
			ps.emplace_back(a, i);
		}
		sort(iter(ps));
		int ans = INF;
		set<int> pos;
		for (int i = 1, j = 0;i <= n;i++) {
			while (ps[j].first <= ps[i].first - x) {
				pos.insert(ps[j].second);
				j++;
			}
			if (!pos.empty()) {
				auto p = pos.lower_bound(ps[i].second);
				if (p != pos.begin()) {
					p--;
					ans = min(ans, (int)ps[i].second - *p);
				}
			}
		}
		cout << (ans == INF ? -1 : ans) << endl;
	}
	return 0;
}

