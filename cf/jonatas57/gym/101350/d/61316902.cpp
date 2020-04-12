#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x) cout <<#x <<" = " <<x <<endl;
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
	ios_base::sync_with_stdio(false);

	int t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		int x, y;
		cin >> x;
		bool p = true;
		for (int i = 0;i < n - 1;i++) {
			cin >> y;
			if (abs(x - y) & 1) p = false;
			x = y;
		}
		cout << (p ? "yes" : "no") << endl;
	}
	
	return 0;
}

