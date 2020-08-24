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
		string s, p;
		cin >> s >> p;
		vi cnts(26, 0), cntp(26, 0);
		each(c, s) cnts[c - 'a']++;
		each(c, p) cntp[c - 'a']++;
		string ans = "";
		bool bef = false;
		for (int i = 0;s[i + 1];i++) {
			if (p[i] != p[i + 1]) {
				bef = p[i + 1] < p[i];
				break;
			}
		}
		loop(26) {
			if (bef and p[0] - 'a' == i) {
				ans += p;
			}
			if (cnts[i] - cntp[i]) {
				ans += string(cnts[i] - cntp[i], 'a' + i);
			}
			if (!bef and p[0] - 'a' == i) {
				ans += p;
			}
		}
		cout << ans << endl;
	}
	return 0;
}

