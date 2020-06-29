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

bool isvowel(char c) {
	c = tolower(c);
	return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	string s;
	while (getline(cin, s)) {
		string t = "";
		for (int i = 0;;i++) {
			if (isalpha(s[i])) {
				t += s[i];
			}
			else {
				if (!t.empty()) {
					if (!isvowel(t[0])) cout << t.substr(1) << t[0];
					else cout << t;
					cout << "ay";
				}
				t.clear();
				if (!s[i]) {
					cout << endl;
					break;
				}
				cout << s[i];
			}
		}
	}
	return 0;
}

