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

ll maxsub(vector<ll>& v, int l, int r) {
	if (l == r) return v[l];
	int mid = avg(l, r);
	ll m = 0, sum = 0;
	for (int i = mid;i >= l;i--) {
		sum += v[i];
		if (m < sum) m = sum;
	}
	sum = m;
	for (int i = mid + 1;i <= r;i++) {
		sum += v[i];
		if (m < sum) m = sum;
	}
	return max({m, maxsub(v, l, mid), maxsub(v, mid + 1, r)});
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		int n;
		cin >> n;
		vector<ll> a(n);
		ll sum = 0;
		loop(n) cin >> a[i], sum += a[i];
		ll x = max(maxsub(a, 0, n - 2), maxsub(a, 1, n - 1));
		cout << (x < sum ? "YES" : "NO") << endl;
	}
	return 0;
}

