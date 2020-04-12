#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define each(x, s)         for(auto& x : s)
#define ceach(x, s)        for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define pb                 push_back

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	vi a(n);
	int neg = 0, pos = 0;
	loop(n) {
		cin >> a[i];
		if (a[i] > 0) pos++;
		else if (a[i] < 0) neg++;
	}
	int x = n / 2 + (n & 1), ans;
	if (x > pos and x > neg) ans = 0;
	else if (pos >= x) ans = 1;
	else ans = -1;
	cout << ans << endl;
	return 0;
}
