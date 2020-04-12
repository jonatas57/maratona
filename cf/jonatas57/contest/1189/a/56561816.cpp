#include <bits/stdc++.h>

using namespace std;

typedef long long              ll;
typedef unsigned long long     ull;
typedef vector<int>            vi;
typedef vector<bool>           vb;
typedef map<int, int>          mii;
typedef pair<int, int>         ii;

#define INF                    0x3f3f3f3f
#define MAX                    100000
#define N                      4 * MAX + 10
#define MOD                    1000000007
#define each(x, s)             for (auto& x : s)
#define loop(x)                for (int i = 0;i < x;i++)
#define vloop(j, x)            for (int j = 0;j < x;j++)
#define avg(l, r)              l + (r - l) / 2
#define iter(a)                a.begin(), a.end()
#define dbg(x)                 cerr << "#x = " << x << endl;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	string s;
	cin >> n >> s;
	if (n == 1) cout << 1 << endl << s << endl;
	else {
		int zero = 0, one = 0;
		each(c, s) if (c == '0') zero++; else one++;
		if (zero != one) cout << 1 << endl << s << endl;
		else {
			cout << 2 << endl << s[0] << " " << s.substr(1) << endl;
		}
	}
	return 0;
}
