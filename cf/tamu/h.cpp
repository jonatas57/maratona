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

int n;
ll k;

bool f(ll x) {
	loop(n - 1) {
		x = 3 * (x - 2);
		if (x > k) return false;
	}
	return x <= k;
}

ll bb(ll l, ll r) {
	if (l == r) return l;
	ll mid = avg(l, r);
	return !f(mid) ? bb(l, mid) : bb(mid + 1, r);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	cin >> n >> k;
	ll ans = bb(3, k);
	while (!f(ans)) ans--;
	cout << ans << endl;
	return 0;
}

