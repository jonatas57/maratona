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
	ll odd = 0, even = 0;
	loop(n) {
		cin >> a[i];
		if (i & 1) odd += a[i];
		else even += a[i];
	}
	odd += a[0];
	ll ans = odd;
	for (int i = 1;i < n;i += 2) {
		odd += a[i + 1] - a[i];
		ans = max(ans, odd);
	}
	ans = max(ans, even);
	for (int i = 0;i < n - 1;i += 2) {
		even += a[i + 1] - a[i];
		ans = max(ans, even);
	}
	cout << ans << endl;
	return 0;
}

