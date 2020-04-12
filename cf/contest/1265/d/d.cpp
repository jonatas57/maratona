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

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	string ab = "", cd = "";
	int x = min(a, b), y = min(c, d);
	loop(x) ab += "0 1 ";
	loop(y) cd += "2 3 ";
	a -= x, b -= x, c -= y, d -= y;
	if (b and c) {
		x = min(b, c);
		b -= x;
		c -= x;
		loop(x) ab += "2 1 ";
	}
	if (a == 1 and !(c + d + cd.length())) ab += "0 ", a--;
	else if (d == 1 and !(a + b + ab.length())) ab += "3 ", d--;
	else if (b == 1) ab = "1 " + ab, b--;
	else if (c == 1) cd += "2 ", c--;
	if (a or d or abs(b - c) > 1) cout << "NO" << endl;
	else {
		cout << "YES" << endl << ab << cd << endl;
	}
	return 0;
}

