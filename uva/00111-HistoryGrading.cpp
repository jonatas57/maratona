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

vi a, ord;
vector<vi> dp;

int solve(int x, int y) {
	if (dp[x][y] == -1) {
		if (x == 0 or y == 0) dp[x][y] = 0;
		else if (a[x - 1] == ord[y - 1]) dp[x][y] = solve(x - 1, y - 1) + 1;
		else dp[x][y] = max(solve(x - 1, y), solve(x, y - 1));
	}
	return dp[x][y];
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	string s;
	bool o = true;
	while (getline(cin, s)) {
		if (s.find(' ') == string::npos) {
			o = true;
			n = stoi(s, nullptr, 10);
		}
		else {
			stringstream ss;
			ss << s;
			int x;
			if (o) {
				ord.resize(n);
				loop(n) ss >> x, ord[x - 1] = i;
				o = false;
			}
			else {
				a.resize(n);
				loop(n) ss >> x, a[x - 1] = i;
				dp.assign(n + 1, vi(n + 1, -1));
				cout << solve(n, n) << endl;
			}
		}
	}
	return 0;
}
