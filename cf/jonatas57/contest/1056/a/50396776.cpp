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

	mii lines;
	int n, r, x;
	cin >> n;
	loop(n) {
		cin >> r;
		loop(r) {
			cin >> x;
			lines[x]++;
		}
	}
	each(l, lines) {
		if (l.second == n) cout << l.first << " ";
	}
	cout << endl;
	return 0;
}
