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

int solve(string& s, string& t) {
	int a = s.length(), b = t.length();
	vector<vi> dp(a + 1, vi(b + 1, 0));
	loop(a) vloop(j, b) {
		if (s[i] == t[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
		else dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
	}
	return dp[a][b];
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	string s, t;
	for (int i = 1;getline(cin, s) and s != "#";i++) {
		getline(cin, t);
		cout << "Case #" << i << ": you can visit at most " << solve(s, t) << " cities." << endl;
	}
	return 0;
}

