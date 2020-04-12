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

	string s, t;
	cin >> s >> t;
	sort(iter(s));
	sort(riter(t));
	int n = s.length();
	string ans(n, '?');
	int si = 0, sj = (n + 1) >> 1, ti = 0, tj = n >> 1;
	for (int i = 0, j = n - 1, k = 0;k < n;k++) {
		if (k & 1) {
			if (t[ti] >= s[si]) ans[i++] = t[ti++];
			else ans[j--] = t[tj--];
		}
		else {
			if (s[si] <= t[ti]) ans[i++] = s[si++];
			else ans[j--] = s[sj--];
		}
	}
	cout << ans << endl;
	return 0;
}

