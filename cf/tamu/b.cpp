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

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	ll n, k, a, b;
	cin >> n >> k >> a >> b;
	bool p = true;
	ll w;
	loop(n) {
		cin >> w;
		ll del = k - w;
		if (del < 0) p = false;
		ll x = del / 2;
		del -= 2 * x;
		b -= x;
		x = 0;
		if (b < 0) x = -b, b = 0;
		del += 2 * x;
		if (del) {
			a -= del;
			if (a < 0) p = false;
		}
	}
	cout << (p ? "YES" : "NO") << endl;
	return 0;
}

