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
	
	int y, b, r;
	cin >> y >> b >> r;

	int total = 0;
	if (r > b) r = b + 1;
	else b = r - 1;
	if (b > y) b = y + 1;
	else y = b - 1;
	if (r - y > 2) r = y + 2;
	total = y + b + r;
	cout << total << endl;
	return 0;
}
