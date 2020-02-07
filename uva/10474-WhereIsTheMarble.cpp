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

	int n, q;
	for (int c = 1;cin >> n >> q and n | q;c++) {
		vi a(n);
		loop(n) cin >> a[i];
		sort(iter(a));
		int x;
		cout << "CASE# " << c << ":" << endl;
		loop(q) {
			cin >> x;
			auto it = lower_bound(iter(a), x);
			if (it == a.end() or *it > x) cout << x << " not found" << endl;
			else cout << x << " found at " << it - a.begin() + 1 << endl;
		}
	}
	return 0;
}

