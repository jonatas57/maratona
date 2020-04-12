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

	freopen("abbreviation.in", "r", stdin);
	freopen("abbreviation.out", "w", stdout);

	string s;
	while (getline(cin, s)) {
		int l = s.length();
		string ab = "";
		int up = 0, last = 0, st = 0;
		char x;
		for (int i = 0, j = 0;j <= l;j++) {
			if (isalpha(s[j])) {
				if (isupper(s[j])) {
					up++;
					x = s[j];
				}
			}
			else {
				bool e = true;
				if (up == 1 and j - st > 1 and isupper(s[st])) {
					ab += x;
					e = false;
					last = j - 1;
				}
				if (e || ispunct(s[j]) || j == l) {
					if (ab.length() > 1) {
						cout << ab << " (";
						while (i <= last) cout << s[i++];
						cout << ")";
					}
					while (i < j) cout << s[i++];
					if (j != l) cout << s[i++];
					ab = "";
				}
				st = j + 1;
				up = 0;
			}
		}
		cout << endl;
	}
	return 0;
}
