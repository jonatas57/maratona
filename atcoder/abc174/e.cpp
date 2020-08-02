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

	int n, k;
	cin >> n >> k;
	vi a(n);
	int m = 0;
	loop(n) cin >> a[i], m = max(m, a[i]);
	int l = 1, r = m;
	int ans = m;
	while (l < r) {
		int mid = avg(l, r);
		int cuts = 0, x = 0;
		loop(n) {
			int y = (a[i] + mid - 1) / mid;
			cuts += y - 1;
			x = max(x, (a[i] + y - 1) / y);
		}
		if (cuts <= k) {
			r = mid;
			ans = min(ans, x);
		}
		else l = mid + 1;
	}
	cout << ans << endl;
	return 0;
}

