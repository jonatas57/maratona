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
	int l = s.length();
	ll ans = 0;
	for (int i = 0;i < l;i++) {
		int r = min(i + 8, l);
		for (int x = i;x < r;x++) {
			for (int k = 1;k <= 3 and x + k + k < r;k++) {
				if (s[x] == s[x + k] and s[x] == s[x + k + k]) {
					r = min(r, x + k + k);
				}
			}
		}
		ans += l - r;
	}
	cout << ans << endl;
	return 0;
}

