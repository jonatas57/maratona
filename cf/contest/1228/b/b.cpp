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
#define endl               "\n"

ll xp(ll b, ll e) {
	if (e == 0) return 1;
	if (e == 1) return b;
	ll c = xp(b, e / 2);
	c *= c;
	c %= MOD;
	if (e & 1) c *= b, c %= MOD;
	return c;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int h, w;
	cin >> h >> w;
	vector<vi> cs(h, vi(w, 0));
	int x;
	bool p = true;
	vi r(h), c(w);
	loop(h) cin >> r[i];
	loop(w) cin >> c[i];
	loop(h) {
		vloop(j, r[i]) cs[i][j] = 1;
		if (r[i] < w) cs[i][r[i]] = -1;
	}
	loop(c[0]) if (cs[i][0] != 1) p = false;
	if (c[0] < h and cs[c[0]][0] != -1) p = false;
	loop(w) { if (i) {
		vloop(j, c[i]) {
			if (cs[j][i] == -1) p = false;
			else cs[j][i] = 1;
		}
		if (c[i] < h) cs[c[i]][i] = -1;
	}}
	int cnt = 0;
	for (int i = 1;i < h;i++) {
		for (int j = 1;j < w;j++) {
			if (cs[i][j] == 0) cnt++;
		}
	}
	cout << (p ? xp(2, cnt) : 0) << endl;
	return 0;
}

