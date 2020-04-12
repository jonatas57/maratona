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
#define keach(k, v, s)     for(auto& [k, v] : s)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define cc(x)              cerr << #x << " = " << x << endl;

set<ll> div(ll x) {
	set<ll> ans;
	for (ll i = 1;i * i <= x;i++) {
		if (x % i == 0) {
			ans.insert(x / i);
			ans.insert(i);
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	ll a, b;
	cin >> a >> b;
	if (a % b == 0) {
		ll x = a / b;
		set<ll> d = div(x);
		each(y, d) {
			cout << b * y << " ";
		}
		cout << endl;
	}
	return 0;
}

