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

	int a, b, c, d, n;
	cin >> a >> b >> c >> d >> n;
	vector<string> ss(max(b, d), string(a + c, '.'));
	bool up = a & 1;
	char p = 'a';
	int x = (up ? b - 1 : 0), y = 0, next, lim = b;
	loop(n) {
		cin >> next;
		while (next) {
			if (up) {
				for (;x >= 0 && next;x--, next--) ss[x][y] = p;
			}
			else {
				for (;x < lim && next;x++, next--) ss[x][y] = p;
			}
			if (x == -1 || x == lim) {
				y++;
				up = !up;
				if (x == -1) x = 0; else x = lim - 1;
			}
			if (y == a) lim = d;
		}
		p++;
	}
	cout << "YES\n";
	each(s, ss) cout << s << endl;
	return 0;
}
