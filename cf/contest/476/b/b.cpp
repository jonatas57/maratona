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

	string s, t;
	cin >> s >> t;
	int l = t.length(), p = 0;
	each(c, s) p += (c == '+' ? 1 : -1);
	mii cnt;
	int q = 0, x = 0;
	loop(l) {
		if (t[i] == '?') x++;
		else q += (t[i] == '+' ? 1 : -1);
	}
	int tot = 0;
	if (x) {
		int mask = 1 << x;
		loop(mask) {
			int r = q;
			vloop(j, x) {
				r += (i & (1 << j) ? 1 : -1);
			}
			cnt[r]++;
			tot++;
		}
	}
	double ans = 1.0 * (p == q);
	if (tot) {
		ans = (double)cnt[p] / tot;
	}
	cout << fixed << setprecision(12) << ans << endl;
	return 0;
}

