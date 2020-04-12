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
	map<ll, int> ids;
	ll last = 0, x, ans = 0;
	int last0 = 0;
	loop(n) {
		cin >> x;
		if (!x) {
			last0 = i + 1;
		}
		x += last;
		ll del = i + 1;
		if (ids[x] or !x) {
			last0 = max(last0, ids[x] + 1);
		}
		ans += del - last0;
		ids[x] = i + 1;
		last = x;
	}
	cout << ans << endl;
	return 0;
}

