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

	int n;
	cin >> n;
	loop(n) {
		int d, m, y, d2, m2, y2;
		char c;
		cin >> d >> c >> m >> c >> y;
		cin >> d2 >> c >> m2 >> c >> y2;
		ii a(m, d), b(m2, d2);
		cout << "Case #" << i + 1 << ": ";
		if (y < y2 or (y2 == y and a < b)) {
			cout << "Invalid birth date" << endl;
		}
		else {
			int ans = y - y2;
			if (a < b) ans--;
			if (ans > 130) cout << "Check birth date" << endl;
			else cout << ans << endl;
		}
	}
	return 0;
}

