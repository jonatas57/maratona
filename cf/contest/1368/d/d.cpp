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
	sort(iter(a));
	for (int b = 1 << 19;b > 0;b >>= 1) {
		for (int i = 0, j = n - 1;i < j;) {
			if (!(a[i] & b)) i++;
			else if (a[j] & b) j--;
			else {
				ll x = a[i], y = a[j];
				a[j] = x | y;
				a[i] = x & y;
				i++;
				j--;
			}
		}
	}
	ll ans = 0;
	each(x, a) {
		ans += x * x;
	}
	cout << ans << endl;
	return 0;
}

