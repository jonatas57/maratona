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

	vector<ll> dp(10001);
	dp[0] = 1;
	for (int i = 1;i <= 10000;i++) {
		dp[i] = dp[i - 1] * i;
		while (dp[i] % 10 == 0) dp[i] /= 10;
		dp[i] %= 1000000000;
	}/*@*/
	loop(20) cerr << dp[i] << " ";
	cerr << endl;/*@*/
	int n;
	while (cin >> n) {
		cout << setw(5) << n;
		cout << " -> " << dp[n] % 10 << endl;
	}
	return 0;
}

