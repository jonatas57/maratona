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

ll n, k;
vector<ll> a;
bool check(ll mid) {
	ll cnt = 0;
	for (int i = 1;i < n;i++) {
		if (a[i]) {
			ll y = mid / a[i];
			if (a[i] > 0) {
				if (a[i] * y != mid and mid > 0) y++;
				cnt += lower_bound(a.begin(), a.begin() + i, y) - a.begin();
			}
			else {
				if (a[i] * y != mid and mid > 0) y--;
				cnt += (a.begin() + i) - upper_bound(a.begin(), a.begin() + i, y);
			}
		}
		else {
			cnt += mid > 0 ? i : 0;
		}
	}
	return cnt < k;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	cin >> n >> k;
	a.resize(n);
	loop(n) cin >> a[i];
	sort(iter(a));
	ll l = -1000000000000000000, r = 1000000000000000001;
	while (l < r) {
		ll mid = avg(l, r);
		if (check(mid)) l = mid + 1;
		else r = mid;
	}
	cout << l - 1 << endl;
	return 0;
}

