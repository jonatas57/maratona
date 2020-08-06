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
		vi a(n);
		loop(n) cin >> a[i];
		sort(iter(a));
		int ans = 0;
		for (int s = 2;s <= n + n;s++) {
			int cnt = 0;
			for (int j = 0, k = n - 1;j < k;) {
				if (a[j] + a[k] == s) {
					cnt++;
					j++;
					k--;
				}
				else if (a[j] + a[k] < s) j++;
				else k--;
			}
			ans = max(ans, cnt);
		}
		cout << ans << endl;
	}
	return 0;
}

