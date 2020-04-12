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
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()

double power(double b, int e) {
	if (e == 1) return b;
	double c = power(b, e / 2);
	c *= c;
	if (e & 1) c *= b;
	return c;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int m, n;
	cin >> m >> n;
	double ans = 0, a, b = 0;
	loop(m) {
		a = (i + 1.0) / m;
		ans += (i + 1) * (power(a, n) - power(b, n));
		b = a;
	}
	cout << ans << endl;
	return 0;
}
