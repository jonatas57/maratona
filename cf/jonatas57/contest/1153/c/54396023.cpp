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

	int n;
	string s;
	cin >> n >> s;
	int o = 0, c = 0;
	vi aux;
	rep(1, n - 1, 1) {
		if (s[i] == '(') o++;
		else if (s[i] == ')') c++;
		else aux.push_back(i);
	}
	bool p = !(n & 1) && s[0] != ')' && s[n - 1] != '(';
	if (p) {
		s[0] = '(';
		s[n - 1] = ')';
		o = n / 2 - o - 1;
		c = n / 2 - c - 1;
		p = o >= 0 && c >= 0;
	}
	if (p) {
		loop(o) s[aux[i]] = '(';
		loop(c) s[aux[o + i]] = ')';
		int cnt = 0;
		for (int i = n - 2;i > 0 && p;i--) {
			cnt += (s[i] == '(' ? -1 : 1);
			p = cnt >= 0;
		}
	}
	cout << (p ? s : ":(") << endl;
	return 0;
}

