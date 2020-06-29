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
	int t;
	cin >> t;
	string s;
	getline(cin, s);
	loop(t) {
		if (i) cout << endl;
		getline(cin, s);
		vector<pair<int, string>> a;
		string fp;
		getline(cin, s);
		int x = 0;
		for (int i = 0;;i++) {
			if (isdigit(s[i])) {
				x *= 10;
				x += s[i] - '0';
			}
			else {
				cin >> fp;
				a.emplace_back(x, fp);
				x = 0;
				if (!s[i]) break;
			}
		}
		sort(iter(a));
		each(p, a) cout << p.second << endl;
		getline(cin, s);
	}
	return 0;
}

