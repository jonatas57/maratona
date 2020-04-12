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

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	mii maxp;
	vi a(n), ans(n, 0);
	loop(n) cin >> a[i];
	ans[n - 1] = 1, maxp[a[n - 1]] = n - 1;
	for (int i = n - 2;i >=0;i--) {
		if (a[i] > 0) ans[i] = ans[i + 1] + 1, maxp[a[i]] = i;
		else {
			int x = maxp[-a[i]];
			if (!x) x = n;
			ans[i] = min(x - i, ans[i + 1] + 1);
		}
	}
	each(x, ans) cout << x << " "; cout << endl;
	return 0;
}
