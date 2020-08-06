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
	vi a(1000000);
	a[0] = 1, a[1] = 2, a[2] = 3;
	loop(t) {
		int n, m, k;
		cin >> n >> m >> k;
		for (int i = 3;i < n;i++) {
			a[i] = (a[i - 1] + a[i - 2] + a[i - 3]) % m + 1;
		}
		vi cnt(k + 1, 0);
		int ans = INF, zero = k;
		for (int i = 0, j = 0;j < n;) {
			if (a[j] <= k) {
				cnt[a[j]]++;
				if (cnt[a[j]] == 1) zero--;
			}
			j++;
			if (!zero) {
				ans = min(ans, j - i);
				while (!zero) {
					if (a[i] <= k) {
						cnt[a[i]]--;
						if (!cnt[a[i]]) zero++;
					}
					i++;
					if (!zero) ans = min(ans, j - i);
				}
			}
		}
		cout << "Case " << i + 1 << ": ";
		if (ans == INF) cout << "sequence nai" << endl;
		else cout << ans << endl;
	}
	return 0;
}

