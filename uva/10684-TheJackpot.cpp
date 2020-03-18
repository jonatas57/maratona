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

int maxsum(vi& a, int l, int r) {
	if (l == r) return a[l];
	int mid = avg(l, r);
	int x = maxsum(a, l, mid), y = maxsum(a, mid + 1, r);
	int sum = 0, m = 0;
	for (int i = mid + 1;i <= r;i++) m += a[i], sum = max(sum, m);
	m = sum;
	for (int i = mid;i >= l;i--) m += a[i], sum = max(m, sum);
	return max({x, y, sum});
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	while (cin >> n and n) {
		vi a(n);
		loop(n) cin >> a[i];
		int ans = maxsum(a, 0, n - 1);
		if (ans == 0) cout << "Losing streak." << endl;
		else cout << "The maximum winning streak is " << ans << "." << endl;
	}
	return 0;
}

