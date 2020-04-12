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

	int t;
	cin >> t;
	while (t--) {
		int l, a;
		cin >> l >> a;
		double alfa = PI / 180 * a;
		double ans = l * l * (alfa - sin(alfa)) / 2;
		cout << fixed << setprecision(6) << ans << endl;
	}
	
	return 0;
}

