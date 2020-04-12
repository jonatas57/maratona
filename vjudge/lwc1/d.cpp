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

typedef tuple<ll, ll, ll> tup;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vector<vector<ll>> cs(8);
	ll x, y, z;
	loop(n) {
		cin >> x >> y >> z;
		loop(8) {
			cs[i].push_back(x * (i & 4 ? 1 : -1) + y * (i & 2 ? 1 : -1) + z * (i & 1 ? 1 : -1));
		}
	}
	ll ans = 0;
	loop(8) {
		sort(riter(cs[i]));
		ll sum = 0;
		vloop(j, m) sum += cs[i][j];
		ans = max(sum, ans);
	}
	cout << ans << endl;
	return 0;
}

