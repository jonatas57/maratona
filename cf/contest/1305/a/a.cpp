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
		int n;
		cin >> n;
		vi a(n), b(n);
		loop(n) cin >> a[i];
		loop(n) cin >> b[i];
		sort(iter(a));
		sort(iter(b));
		vb used(2001, false), usedb(1001, false);
		vector<ii> ans;
		each(x, a) {
			each(y, b) {
				if (usedb[y]) continue;
				if (!used[x + y]) {
					ans.emplace_back(x, y);
					usedb[y] = true;
					break;
				}
			}
		}
		loop(n) cout << ans[i].first << " ";
		cout << endl;
		loop(n) cout << ans[i].second << " ";
		cout << endl;
	}
	return 0;
}

