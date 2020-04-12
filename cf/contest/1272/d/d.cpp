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
	vi a(n), cres(n, 1);
	loop(n) {
		cin >> a[i];
		if (i and a[i] > a[i - 1]) cres[i] = cres[i - 1] + 1;
	}
	int last = cres[n - 1];
	for (int i = n - 2;i >= 0;i--) {
		int tmp = cres[i];
		if (last != 1) {
			cres[i] = cres[i + 1];
		}
		last = tmp;
	}
	int ans = cres[0];
	for (int i = cres[0];i < n;) {
		int l = cres[i - 1], r = cres[i];
		ans = max(ans, r);
		for (int j = i;j <= i + 1;j++) {
			int x = j < 2 ? 0 : a[j - 2];
			int y = j < n ? a[j] : 0;
			if (x < y) {
				ans = max(ans, l + r - 1);
			}
		}
		i += cres[i];
	}
	cout << ans << endl;
	return 0;
}

