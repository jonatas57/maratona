#include <bits/stdc++.h>

using namespace std;

typedef long long 				ll;
typedef unsigned long long 		unll;
typedef vector<int>				vi;
typedef vector<bool>			vb;
typedef map<int, int> 			mii;
typedef pair<int, int>			ii;

#define INF 					0x3f3f3f3f
#define each(x, s) 				for(auto const& x : s)
#define rep(x, y, z)			for(int i = x;i < y;i+=z)
#define loop(x)					for(int i = 0;i < x;i++)

#define push_back				pb

int main() {
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	vi a(n);
	loop(n) {
		cin >> a[i];
	}
	int mine = INF;
	loop(n) {
		int e = 0;
		for (int j = 0;j < n;j++) {
			e += (abs(i - j) + j + i) * 2 * a[j];
		}
		mine = min(e, mine);
	}
	cout << mine << endl;
	return 0;
}
