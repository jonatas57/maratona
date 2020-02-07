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

string a, b;
vector<vi> lcs;

int solve(int x, int y) {
	if (lcs[x][y] == -1) {
		if (x == 0 or y == 0) lcs[x][y] = 0;
		else if (a[x - 1] == b[y - 1]) lcs[x][y] = solve(x - 1, y - 1) + 1;
		else lcs[x][y] = max(solve(x - 1, y), solve(x, y - 1));
	}
	return lcs[x][y];
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	while (getline(cin, a) and getline(cin, b)) {
		int la = a.length(), lb = b.length();
		lcs.assign(la + 1, vi(lb + 1, -1));
		cout << solve(la, lb) << endl;
	}
	return 0;
}

