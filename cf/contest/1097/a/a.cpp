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

	string card, hand;
	cin >> card;
	bool can = false;
	loop(5) {
		cin >> hand;
		can |= (hand[0] == card[0] || hand[1] == card[1]);
	}
	cout << (can ? "YES": "NO") << endl;
	return 0;
}
