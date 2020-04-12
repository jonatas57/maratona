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
	vector<ll> a(n), pre(n, 0), suf(n, 0);
	loop(n) {
		cin >> a[i];
	}
	for (int i = 1;i < n;i++) {
		pre[i] |= pre[i - 1] | a[i - 1];
		suf[n - 1 - i] |= suf[n - i] | a[n - i];
	}
	ll ans = 0;
	int id = 0;
	loop(n) {
		int x = (a[i] | pre[i] | suf[i]) - (pre[i] | suf[i]);
		if (ans < x) {
			ans = x;
			id = i;
		}
	}
	cout << a[id];
	loop(n) if (i != id) cout << " " << a[i];
	cout << endl;
	return 0;
}
