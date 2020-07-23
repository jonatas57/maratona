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

struct eq {
	vector<vi> sides;
	bool imp, id;
	eq(string& s) : sides(2, vi(2, 0)), imp(false), id(false) {
		int x = 0, sig = 1;
		bool r = false, ok = false;
		for (int i = 0;;i++) {
			if (isdigit(s[i])) {
				x *= 10;
				x += s[i] - '0';
				ok = true;
			}
			else if (s[i] == 'x') {
				sides[r][0] += sig * (ok ? x : 1);
				ok = false;
				x = 0;
			}
			else {
				sides[r][1] += x * sig;
				ok = false;
				x = 0;
				if (!s[i]) break;
				if (s[i] == '=') r = true, ok = false, sig = 1;
				else sig = s[i] == '+' ? 1 : -1;
			}
		}

		sides[0][0] -= sides[1][0];
		sides[1][0] = 0;
		sides[1][1] -= sides[0][1];
		sides[0][1] = 0;
		if (sides[0][0] == 0) {
			imp = sides[1][1];
			id = !sides[1][1];
		}
	}
	int solve() {
		int x = sides[1][1] / sides[0][0];
		if (x < 0 and sides[1][1] % sides[0][0]) x--;
		return x;
	}
};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	string s;
	cin >> n;
	loop(n) {
		cin >> s;
		eq e(s);
		if (e.imp) cout << "IMPOSSIBLE" << endl;
		else if (e.id) cout << "IDENTITY" << endl;
		else cout << e.solve() << endl;
	}
	return 0;
}

