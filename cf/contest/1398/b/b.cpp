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

	int t;
	cin >> t;
	loop(t) {
		string s;
		cin >> s;
		vi ones;
		int cnt = 1, n = 0;
		for (int i = 1;;i++) {
			if (s[i] == s[i - 1]) cnt++;
			else {
				if (s[i - 1] == '1') n++, ones.push_back(cnt);
				cnt = 1;
			}
			if (!s[i]) break;
		}
		sort(riter(ones));
		int ans = 0;
		for (int i = 0;i < n;i += 2) ans += ones[i];
		cout << ans << endl;
	}
	return 0;
}

