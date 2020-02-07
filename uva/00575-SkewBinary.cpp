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

vi memo(40, -1);

int xp(int e) {
	if (e == 0) return 1;
	if (e == 1) return 2;
	if (memo[e] != -1) return memo[e];
	int c = xp(e >> 1);
	c *= c;
	if (e & 1) c *= 2;
	return memo[e] = c;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	string s;
	while (cin >> s and s != "0") {
		int l = s.length(), ans = 0;
		loop(l) {
			ans += (s[i] - '0') * (xp(l - i) - 1);
		}
		cout << ans << endl;
	}
	return 0;
}

