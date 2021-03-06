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

	int t;
	cin >> t;
	loop(t) {
		vi a(3), b(3);
		loop(3) cin >> a[i];
		loop(3) cin >> b[i];
		ll c = 0;
		vector<ii> aux = {{2, 1}, {0, 2}, {0, 0}, {0, 1}, {1, 0}, {1, 1}, {2, 0}, {2, 2}, {1, 2}};
		for (auto& [i, j] : aux) {
			int x = min(a[i], b[j]);
			c += (i > j ? i * j : i < j ? -(i * j) : 0) * x;
			a[i] -= x;
			b[j] -= x;
		}
		cout << c << endl;
	}
	return 0;
}

