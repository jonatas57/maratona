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
	vi a(n), pos;
	loop(n) cin >> a[i], pos.emplace_back(a[i], i);
	ll ans = 0;
	int lim = 0, del = 0, id = 0;
	vb used(n, false), minor(n, false);
	sort(iter(pos));
	loop(n) {
		ll x = min(a[i] - i - 1, n - i - 1);
		while (id < n and pos[id].first < x) {
		}
	}
	cout << ans << endl;
	return 0;
}

