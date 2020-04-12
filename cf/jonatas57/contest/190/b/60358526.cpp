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

int main() {
	int x1, y1, r1, x2, y2, r2;
	cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
	if (r2 > r1) swap(r1, r2), swap(x1, x2), swap(y1, y2);
	double ans, dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	if (dist >= r1 + r2) {
		ans = dist - r1 - r2;
	}
	else if (dist <= r1 - r2) {
		ans = r1 - dist - r2;
	}
	else {
		ans = 0;
	}
	printf("%.15lf\n", ans / 2);
	return 0;
}
