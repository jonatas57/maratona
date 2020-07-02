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

set<string> x;
vi ok(10001, false);

void cut(string& s, int n, string last = "", int check = 0) {
	if (n < 4 or ok[n] & check) return;
	ok[n] |= check;
	string a = s.substr(n - 2, 2), b = s.substr(n - 3, 3);
	if (n >= 7 and a != last) {
		x.insert(a);
		cut(s, n - 2, a, 1);
	}
	if (n >= 8 and b != last) {
		x.insert(b);
		cut(s, n - 3, b, 2);
	}
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	string s;
	cin >> s;
	cut(s, s.length());
	cout << x.size() << endl;
	each(s, x) cout << s << endl;
	return 0;
}

