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

	ll n;
	cin >> n;
	int k = log10(n) + 1;
	if (k & 1) k++;
	int mask = (1 << k) - 1, x = k >> 1; 
	ll ans = INFLL;
	for (int i = 1;i < mask;i++) {
		if (__builtin_popcount(i) == x) {
			ll sum = 0;
			vloop(j, k) {
				sum *= 10;
				if (i & (1 << j)) sum += 7;
				else sum += 4;
			}
			if (sum >= n) ans = min(ans, sum);
		}
	}
	if (ans == INFLL) {
		x++;
		ans = 0;
		loop(x) ans *= 10, ans += 4;
		loop(x) ans *= 10, ans += 7;
	}
	cout << ans << endl;
	return 0;
}

