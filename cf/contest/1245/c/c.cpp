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

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	string s;
	cin >> s;
	int n;
	vector<ll> ans(n = s.length(), 1);
	for (int i = 0;i < n;i++) {
		if (s[i] == 'm' or s[i] == 'w') {
			ans[n] = 0;
			break;
		}
		else if (i and (s[i] == 'n' or s[i] == 'u') and s[i] == s[i - 1]) {
			ans[i + 1] = ans[i] + ans[i - 1];
		}
		else ans[i + 1] = ans[i];
		ans[i + 1] %= mod;
	}
	cout << ans[n] << endl;
	return 0;
}

