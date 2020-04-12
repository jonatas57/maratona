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
	string ans = "", aux = "No solution";
	bool bef = true, pos = false;
	int cnt = 0, l = s.length();
	char c;
	while (isalpha(s[l - 1]) and l) l--;
	if (l == s.length()) l = 0, ans = aux;
	for (int i = 0;i < l and (c = (s[i]));i++) {
		if (c == '@') {
			pos = true;
			if (bef and cnt) {
				ans += c;
				bef = false;
				cnt = 0;
			}
			else {
				ans = aux;
				break;
			}
		}
		else {
			cnt++;
			ans += c;
			if (!bef) {
				ans += ',';
				bef = true;
				cnt = 0;
			}
		}
	}
	if (!pos) ans = aux;
	if (ans != aux) {
		ans += s.substr(l);
	}
	cout << ans << endl;
	return 0;
}

