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
#define endl               "\n"

int n, p, k;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		cin >> n >> p >> k;
		vi a(n), acc(n + 1);
		loop(n) cin >> a[i];
		sort(iter(a));
		int ans = 0;
		acc[0] = 0;
		for (int i = 1;i <= n;i++) {
			if (p >= (acc[i] = (i >= k ? acc[i - k] + a[i - 1] : acc[i - 1] + a[i - 1]))) {
				ans = i;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

