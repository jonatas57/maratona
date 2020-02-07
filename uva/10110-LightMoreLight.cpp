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

ll div(ll n) {
	ll ans = 1;
	while (n % 2 == 0) ans++, n /= 2;
	for (ll i = 3;i * i <= n;i += 2) {
		ll cnt = 1;
		while (n % i == 0) {
			cnt++;
			n /= i;
		}
		if (cnt > 1) ans *= cnt;
	}
	if (n > 1) ans *= 2;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	ll n;
	while (cin >> n and n) {
		cout << (div(n) & 1 ? "yes" : "no") << endl;
	}
	return 0;
}

