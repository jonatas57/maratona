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
#define endl               "\n"

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int l, r;
	cin >> l >> r;
	int ans = -1;
	for (int i = l;i <= r and ans == -1;i++) {
		string s = to_string(i);
		vi cnt(10, 0);
		each(c, s) {
			cnt[c - '0']++;
		}
		int x = 0;
		loop(10) {
			if (cnt[i] > 1) x++;
		}
		if (x) ans = -1; else ans = i;
	}
	cout << ans << endl;
	return 0;
}
