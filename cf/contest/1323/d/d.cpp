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
	cin >> n;
	vi a(n);
	loop(n) cin >> a[i];
	int ans = 0;
	for (int k = 1 << 25, k2 = k << 1;k > 0;k >>= 1, k2 >>= 1) {
		loop(n) a[i] %= k2;
		sort(iter(a));
		int cnt = 0;
		loop(n) {
			int x = upper_bound(iter(a), k2 - 1 - a[i]) - lower_bound(iter(a), k - a[i]);
			x += upper_bound(iter(a), k2 + k2 - 2 - a[i]) - lower_bound(iter(a), k2 + k - a[i]);
			if (a[i] & (k >> 1)) x--;
			cnt += x;
		}
		cnt >>= 1;
		if (cnt & 1) ans += k;
	}
	cout << ans << endl;
	return 0;
}

