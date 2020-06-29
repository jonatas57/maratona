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
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		int a, b, c, d, e, f, g;
		cin >> a >> b >> c >> d >> e >> f >> g;
		int s = e + f + g - min({e, f, g});
		int x = a + b + c + d + s / 2;
		cout << "Case " << i + 1 << ": ";
		if (x >= 90) cout << "A" << endl;
		else if (x >= 80) cout << "B" << endl;
		else if (x >= 70) cout << "C" << endl;
		else if (x >= 60) cout << "D" << endl;
		else cout << "F" << endl;
	}
	return 0;
}

