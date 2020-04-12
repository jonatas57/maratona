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
	
ll b, s, c, pb, ps, pc;
ll qb = 0, qs = 0, qc = 0;
ll r;

ll bb(ll l, ll h) {
	if (l == h - 1) return l;
	ll mid = avg(l, h);
	ll nb = max(mid * qb - b, 0ll), ns = max(mid * qs - s, 0ll), nc = max(mid * qc - c, 0ll);
	ll cost = nb * pb + ns * ps + nc * pc;
	return (cost > r ? bb(l, mid) : bb(mid, h));
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	string ham;
	cin >> ham;
	cin >> b >> s >> c >> pb >> ps >> pc >> r;
	each(c, ham) {
		if (c == 'B') qb++;
		else if (c == 'S') qs++;
		else qc++;
	}
	cout << bb(0, r + 1000) << endl;	
}
