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

vector<ll> solve(ll sum, ll xr) {
	vector<ll> ans;
	ll xr2 = 2 * xr;
	if (sum > xr2) {
		if (xr) ans.push_back(xr);
		ans.push_back(sum + xr);
	}
	else if (sum < xr2) {
		ll del = xr2 - sum;
		if (del & 1) {
			ans.push_back(1);
			auto aux = solve(sum + 1, xr ^ 1);
			ans.insert(ans.end(), iter(aux));
		}
		else {
			del >>= 1;
			loop(2) ans.push_back(del);
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		int n;
		cin >> n;
		vector<ll> a(n);
		ll sum = 0, xr = 0;
		loop(n) {
			cin >> a[i];
			sum += a[i];
			xr  ^= a[i];
		}
		vector<ll> ans = solve(sum, xr);
		cout << ans.size() << endl;
		each(x, ans) cout << x << " ";
		cout << endl;
	}
	return 0;
}

