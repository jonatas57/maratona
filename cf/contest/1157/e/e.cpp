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

	int n, x;
	cin >> n;
	vi a(n);
	multiset<int> b;
	loop(n) cin >> a[i];
	loop(n) cin >> x, b.insert(x);
	vi c(n);
	loop(n) {
		auto it = b.lower_bound(n - a[i]);
		if (it == b.end()) it = b.begin();
		c[i] = (a[i] + *it) % n;
		b.erase(it);
	}
	each(x, c) cout << x << " ";
	cout << endl;
	return 0;
}

