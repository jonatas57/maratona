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

	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	loop(n) cin >> a[i];
	sort(iter(a));
	ll p = 0;
	int ans1, ans2;
	k--;
	for (int i = 0, j = 0;i < n;i++) {
		j = i;
		while (j < n and a[i] == a[j]) j++;
		ll x = j - i;
		if (p + x * n <= k) {
			p += x * n;
			i = j - 1;
			continue;
		}
		ll y = k - p;
		ans1 = a[i], ans2 = a[y / x];
		break;
	}
	cout << ans1 << " " << ans2 << endl;
	return 0;
}

