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

char getChar(char a, char b) {
	char c = 'a';
	loop(2) {
		if (c == a or c == b) c++;
		if (c == 'd') c = 'a';
	}
	return c;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	string s;
	cin >> t;
	loop(t) {
		cin >> s;
		bool p = true;
		loop(s.length()) {
			if (s[i] == s[i + 1] and s[i] != '?') p = false;
		}
		loop(s.length()) {
			if (s[i] == '?') {
				s[i] = getChar(i ? s[i - 1] : '?', s[i + 1]);
			}
		}
		if (p) cout << s << endl;
		else cout << -1 << endl;
	}
	return 0;
}

