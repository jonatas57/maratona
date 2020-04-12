#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define MAX                100000
#define N                  4 * MAX + 10
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define ceach(x, s)        for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2

bool comp(ii a, ii b) {
	int x = a.first - a.second;
	int y = b.first - b.second;
	if (x > y) return true;
	return x == y && a.first > b.first;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	vector<ii> a(n);
	loop(n) cin >> a[i].first >> a[i].second;
	sort(a.begin(), a.end(), comp);
	ll ans = 0, alive = 0;
	each(p, a) {
		ll x, y;
		tie(x, y) = p;
		ll aux = max(0ll, x - alive);
		alive += aux;
		ans += aux;
		alive -= y;
	}
	cout << ans << endl;
	return 0;
}

