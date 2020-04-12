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

vector<vi> dp;

string lcs(string s, string t) {
	int ls = s.length();
	dp.assign(ls + 1, vi(ls + 1, 0));
	loop(ls) {
		vloop(j, ls) {
			if (s[i] == t[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
			else dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
		}
	}
	string ans(dp[ls][ls], ' ');
	for (int i = ls, j = ls, id = dp[ls][ls];i > 0 and j > 0;) {
		if (s[i - 1] == t[j - 1]) {
			ans[--id] = s[i - 1];
			i--;
			j--;
		}
		else if (dp[i - 1][j] > dp[i][j - 1]) i--;
		else j--;
	}
	int l = 0, r = 0, la = ans.length();
	for (;l < ls and s[l] == ans[l];l++);
	for (;r < la and t[r] == ans[la - r - 1];r++);/*@*/cerr << l << " " << r << endl;/*@*/
	if (l + r < ls) {
		int x = min(l, r);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	loop(n) {
		string s;
		cin >> s;
		string x(riter(s));
		cout << lcs(s, x) << endl;
	}
	return 0;
}
