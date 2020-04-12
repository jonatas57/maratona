#include <bits/stdc++.h>

using namespace std;

typedef long long 				ll;
typedef unsigned long long 		ull;
typedef vector<int>				vi;
typedef vector<bool>			vb;
typedef map<int, int> 			mii;
typedef pair<int, int>			ii;

#define INF 					0x3f3f3f3f
#define each(x, s) 				for(auto& x : s)
#define ceach(x, s) 			for(auto const& x : s)
#define rep(x, y, z)			for(int i = x;i < y;i+=z)
#define loop(x)					for(int i = 0;i < x;i++)

int main() {
	ios_base::sync_with_stdio(false);

	int w, h;
	cin >> w >> h;
	int u1, d1, u2, d2;
	cin >> u1 >> d1 >> u2 >> d2;

	for (int i = h;i > 0;i--) {
		w += i;
		if (i == d1) w -= w < u1 ? w : u1;
		if (i == d2) w -= w < u2 ? w : u2;
	}
	cout << w << endl;
	return 0;
}
