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
		ll x, ans = 0, last = 0, max0 = 0;
		mii cnt;
		cnt[0]++;
		for (int i = 1;i <= n;i++) {
			cin >> x;
			if (x) {
				while (x % 2 == 0) x /= 2, last++;
				ans += i - max0 - cnt[last - 1];
				cnt[last]++;
			}
			else {
				max0 = i;
				cnt.clear();
				cnt[last]++;
			}
			ans += max0;
		}
		cout << ans << endl;
	}
	return 0;
}
