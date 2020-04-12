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

ll mod;

ll xp(ll b, ll e) {
	if (e == 0) return 1;
	ll c = xp(b, e >> 1);
	c = c * c % mod;
	if (e & 1) c = c * b % mod;
	return c;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int c;
	while (cin >> c and c) {
		loop(c) {
			ll x, y;
			cin >> x >> y >> mod;
			cout << xp(x, y) << endl;
		}
	}
	return 0;
}

