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

	vector<string> pos = {"abc", "acb", "bac", "bca", "cab", "cba"};

	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	if (s[0] == t[0] && s[1] != t[1] && s[0] != s[1] && t[0] != t[1]) {
		cout << "YES" << endl;
		cout << string(n, s[1]) << string(n, t[1]) << string(n, s[0]) << endl;
	}
	else if (s[0] != t[0] && s[1] == t[1] && s[0] != s[1] && t[0] != t[1]) {
		cout << "YES" << endl;
		cout << string(n, s[1]) << string(n, t[0]) << string(n, s[0]) << endl;
	}
	else if (s[0] == t[1] && s[1] == t[0] && s[1] != s[0]) {
		char c = 'a';
		loop(2) if (c == s[0] || c == s[1]) c++;
		cout << "YES" << endl;
		cout << string(n, s[0]) << string(n, c) << string(n, s[1]) << endl;
	}
	else {
		each(str, pos) {
			bool p = true;
			loop(3) {
				if ((str[i] != s[0] || str[(i + 1) % 3] != s[1]) &&
					(str[i] != t[0] || str[(i + 1) % 3] != t[1])) {
						p &= true;
				}
				else p = false;
			}
			if (p) {
				cout << "YES\n";
				loop(n) cout << str;
				cout << endl;
				return 0;
			}
		}
		cout << "NO\n";
	}
	return 0;
}
