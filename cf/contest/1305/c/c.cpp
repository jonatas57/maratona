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

int m;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vi cnt(m, 0), a(m);
	int x, ans = 1;
	loop(n) {
		cin >> x;
		if (cnt[x % m]++) ans = 0;
		a[x % m] = x;
	}
	for (int i = 1;i < m and ans;i++) {
		for (int j = i;j < m and ans;j++) {
			if (cnt[j] and cnt[j - i]) {
				ans *= a[j] < a[j - i] ? m - i : i;
				ans %= m;
			}
		}
	}
	cout << ans << endl;
	return 0;
}

