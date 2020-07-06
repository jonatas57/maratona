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

	int n;
	cin >> n;
	vector<ll> a(n);
	loop(n) cin >> a[i];
	ll ans = 0;
	sort(riter(a));
	priority_queue<tuple<ll, ll, ll>> pos;
	pos.emplace(a[0], a[0], a[0]);
	for (int i = 1;i < n;i++) {
		auto [v, l, r] = pos.top();
		pos.pop();
		ans += v;
		pos.emplace(a[i], l, a[i]);
		pos.emplace(a[i], a[i], r);
	}
	cout << ans << endl;
	return 0;
}

