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

	int t, n;
	double d, a;
	while (cin >> t >> d >> a >> n and t >= 0) {
		int x, ans = 0, lastx = -1;
		vector<double> deps(t + 1);
		double y, car = a + d, p = a / t;
		loop(n) {
			cin >> x >> y;
			deps[x] = y;
			for (int j = lastx + 1;j < x;j++) deps[j] = deps[lastx];
			lastx = x;
		}
		for (int j = lastx + 1;j <= t;j++) deps[j] = deps[lastx];
		a += p;
		loop(t + 1) {
			a -= p;
			car *= 1 - deps[i];
			if (car > a) {
				ans = i;
				break;
			}
		}
		cout << ans << " month" << (ans != 1 ? "s\n" : "\n");
	}
	return 0;
}

