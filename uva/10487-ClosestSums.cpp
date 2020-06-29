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
	for (int t = 1;cin >> n and n;t++) {
		vi a(n), sums;
		loop(n) {
			cin >> a[i];
			vloop(j, i) {
				sums.push_back(a[i] + a[j]);
			}
		}
		sort(iter(sums));
		int m;
		cin >> m;
		cout << "Case " << t << ":" << endl;
		loop(m) {
			int x;
			cin >> x;
			auto p = lower_bound(iter(sums), x);
			int y = *p, z = INF;
			if (p != sums.begin()) {
				p--;
				z = *p;
			}
			int ans = abs(x - z) < abs(x - y) ? z : y;
			cout << "Closest sum to " << x << " is " << ans << "." << endl;
		}
	}
	return 0;
}

