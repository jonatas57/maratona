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

	string s;
	int k, ans = 0;
	cin >> s >> k;
	string forb;
	loop(k) {
		cin >> forb;
		int a = 0, b = 0;
		for (int i = 0;i <= s.length();i++) {
			char c = s[i];
			if (c == forb[0]) a++;
			else if (c == forb[1]) b++;
			else {
				if (a && b) ans += min(a, b);
				a = 0, b = 0;
			}
		}
	}
	cout << ans << endl;
	return 0;
}