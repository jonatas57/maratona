#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define MAX                100000
#define N                  4 * MAX + 10
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define ceach(x, s)        for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	string s;
	cin >> s;
	int l = s.length();
	bool p = !(l & 1);
	int op = 0, cl = 0;
	vi x;
	if (p) {
		loop(l) {
			if (s[i] == '(') op++;
			else if (s[i] == ')') cl++;
			else x.push_back(i);
		}
		op = l / 2 - op;
		cl = l / 2 - cl;
		loop(op) s[x[i]] = '(';
		loop(cl) s[x[op + i]] = ')';
		int c = 0;
		loop(l) {
			if (s[l - i - 1] == ')') c++;
			else c--;
			if (c < 0) {
				p = false;
				break;
			}
		}
	}
	cout << (p ? s : "Impossible") << endl;
	return 0;
}

