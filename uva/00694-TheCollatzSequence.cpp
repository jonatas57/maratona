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

int collatz(ll a, ll l) {
	if (a > l) return 0;
	if (a == 1) return 1;
	if (a & 1) return 1 + collatz(3 * a + 1, l);
	return 1 + collatz(a / 2, l);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	ll a, l;
	for (int t = 1;cin >> a >> l and (a >= 0 or l >= 0);t++) {
		cout << "Case " << t << ": A = " << a << ", limit = " << l << ", number of terms = " << collatz(a, l) << endl;
	}
	return 0;
}

