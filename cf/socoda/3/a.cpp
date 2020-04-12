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

vi t, d, p, ans;
vector<vi> dp;

int solve(int at, int x) {
	if (dp[at][x] == -1) {
		if (at == 0 or x == 0) dp[at][x] = 0;
		dp[at][x] = 
	}
	return dp[at][x];
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	t.resize(n);
	p.resize(n);
	int a, b, c, qtd = 0, maxd = 0;
	loop(n) {
		cin >> a >> b >> c;
		if (a >= b) continue;
		t.push_back(a);
		d.push_back(b);
		p.push_back(c);
		qtd++;
		maxd = max(maxd, b);
	}
	dp.resize(qtd + 1, vi(maxd + 1, -1));
	cout << solve(qtd, maxd) << endl;
	cout << ans.size() << endl;
	each(x, ans) cout << x + 1 << " ";
	cout << endl;
	return 0;
}

