#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mk make_pair
#define cc(x) cout <<#x <<" = " <<x <<endl

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
	ios_base::sync_with_stdio(false);

	int l, r, m;
	cin >> l >> r;
	if (l == r and l) cout << "Even " << l + r << endl;
	else if ((m = max(l, r))) cout << "Odd " << m + m << endl;
	else cout << "Not a moose" << endl;

	return 0;
}

