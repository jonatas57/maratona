#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x) cout <<#x <<" = " <<x <<endl;
#define loop(n) for(int i = 0;i < n;i++)
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

	int t, c, n;
	cin >> t;
	while (t--) {
		cin >> c >> n;
		unordered_map<string, double> curr;
		string s;
		loop(c) {
			cin >> s;
			cin >> curr[s];
		}
		curr["JD"] = 1;
		double ans = 0, x;
		loop(n) {
			cin >> x >> s;
			ans += x * curr[s];
		}
		cout << fixed << setprecision(6) << ans << endl;
	}
	
	return 0;
}

