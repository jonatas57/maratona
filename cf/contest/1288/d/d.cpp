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

vector<vi> a;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	a.assign(n, vi(m));
	loop(n) vloop(j, m) cin >> a[i][j];
	ii ans;
	for (int l = 0, r = 1e9 + 1;l < r;) {
		int x = avg(l, r);
		set<int> masks;
		mii conv;
		loop(n) {
			int mask = 0;
			vloop(j, m) if (x <= a[i][j]) mask |= (1 << j);
			conv[mask] = i + 1;
			masks.insert(mask);
		}
		vi ms(iter(masks));
		int s = ms.size();
		bool p = false;
		loop(s) {
			for (int j = i;j < s;j++) {
				if (__builtin_popcount(ms[i] | ms[j]) == m) {
					ans = {conv[ms[i]], conv[ms[j]]};
					p = true;
					break;
				}
			}
		}
		if (p) l = x + 1;
		else r = x;
	}
	cout << ans.first << " " << ans.second << endl;
	return 0;
}

