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

	string l = "BFPVCGJKQSXZDTLMNR";
	string n = "111122222222334556";
	map<char, char> conv;
	for (int i = 0;l[i];i++) conv[l[i]] = n[i];

	string s;
	while (cin >> s) {
		string t = "";
		char last = ' ';
		for (int i = 0;s[i];i++) {
			char c;
			if (conv.count(s[i])) {
				c = conv[s[i]];
				if (c != last) t += c;
				last = c;
			}
			else last = ' ';
		}
		cout << t << endl;
	}
	return 0;
}

