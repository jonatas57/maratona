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

ll n, m, k;

bool check(ll x) {
	ll cnt = 0;
	for (int i = 1;i <= n;i++) {
		cnt += min(m, x / i);
	}
	return cnt < k;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	cin >> n >> m >> k;
	if (n > m) swap(n, m);
	ll l = 1, r = n * m;
	while (l < r) {
		ll mid = avg(l, r);
		if (check(mid)) l = mid + 1;
		else r = mid;
	}
	cout << l << endl;
	return 0;
}

