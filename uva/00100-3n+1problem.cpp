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

int len(int x) {
	return x == 1 ? 1 : 1 + len(x & 1 ? 3 * x + 1 : x / 2);
}

int query(int l, int r) {
	int ans = 0;
	for (int i = l;i <= r;i++) {
		ans = max(ans, len(i));
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int l, r;
	while (cin >> l >> r) {
		cout << l << " " << r << " ";
		if (l > r) swap(l, r);
		cout << query(l, r) << endl;
	}
	return 0;
}

