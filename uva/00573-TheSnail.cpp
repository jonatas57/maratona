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

	int h, u, d, f;
	while (cin >> h >> u >> d >> f and h) {
		h *= 100, f *= u, u *= 100, d *= 100;
		int ans, x = 0;
		for (int del = u, i = 1;;del = max(0, del - f), i++) {
			x += del;
			if (x > h) {
				ans = i;
				break;
			}
			x -= d;
			if (x < 0) {
				ans = i;
				break;
			}
		}
		cout << (x < 0 ? "failure" : "success") << " on day " << ans << endl;
	}
	return 0;
}

