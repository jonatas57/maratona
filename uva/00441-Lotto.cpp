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

	int k;
	int st = (1 << 6) - 1;
	for (int i = 0;cin >> k and k;i++) {
		if (i) cout << endl;
		string a = "";
		int x;
		loop(k) cin >> x, a += (char)x;
		vector<string> ans;
		for (int i = st;i <= st << (k - 6);i++) {
			if (__builtin_popcount(i) == 6) {
				ans.emplace_back();
				vloop(j, k) {
					if (i & (1 << j)) ans.back() += a[j];
				}
			}
		}
		sort(iter(ans));
		each(s, ans) {
			bool p = false;
			each(c, s) cout << (p ? " " : "") << (int)c, p = true;
			cout << endl;
		}
	}
	return 0;
}

