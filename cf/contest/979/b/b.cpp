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

int calc(string& s, int k) {
	int m = 0;
	int n = s.length();
	map<char, int> cnt;
	each(c, s) m = max(m, ++cnt[c]);
	return k == 1 and n == m ? m - 1 : m + min(n - m, k);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	vector<ii> rnk(3);
	vector<string> ans = {"Kuro", "Shiro", "Katie"};
	string s;
	loop(3) {
		cin >> s;
		rnk[i] = make_pair(calc(s, n), i);
	}
	sort(riter(rnk));
	if (rnk[0].first == rnk[1].first) cout << "Draw" << endl;
	else cout << ans[rnk[0].second] << endl;
	return 0;
}

