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
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	int u, cnt = 0, cntc = 0, ans;
	vi cntcol(100001, 0), cnttim(100001, 0);
	loop(n) {
		cin >> u;
		if (!--cnttim[cntcol[u]]) cnt--;
		if (!cntcol[u]++) cntc++;
		if (!cnttim[cntcol[u]]++) cnt++;
		if (cntc == 1 or (cnt == 1 and cnttim[1]) or (cnt == 2 and cnttim[1] == 1) or (cnt == 2 and (cnttim[cntcol[u] + 1] == 1 or cnttim[cntcol[u] - 1] == cntc - 1))) {
			ans = i;
		}
	}
	cout << ans + 1 << endl;
	return 0;
}
