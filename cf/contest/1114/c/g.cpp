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

	ll n, m;
	cin >> n >> m;
	vector<pair<ll, ll>> fs;
	ll m2 = m;
	for (ll i = 2;i * i <= m2;i++) {
		ll cnt = 0;
		while (m2 % i == 0) {
			cnt++;
			m2 /= i;
		}
		if (cnt) fs.emplace_back(i, cnt);
	}
	if (m2 > 1) fs.emplace_back(m2, 1);
	ll ans = INFLL;
	each(f, fs) {
		ll cnt = 0;
		for (ll i = f.first;i <= n;i *= f.first) {
			cnt += n / i;
			if (i > n / f.first) break;
		}
		ans = min(ans, cnt / f.second);
	}
	cout << ans << endl;
	return 0;
}

