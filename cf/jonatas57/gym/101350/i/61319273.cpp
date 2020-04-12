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

const int T = 1002;
int dp[T][T];
int ok[T];
int vis[T][T];
int vez;
string s;
int n;

int solve(int l, int r) {
	if(l > r) return 0;
	if(l == r) return ok[l];
	if(vis[l][r] == vez) return dp[l][r];

	int x = solve(l+1,r);
	int y = solve(l,r-1);
	int z = 0;

	if(ok[l] and ok[r] and s[l] == s[r]) {
		z = solve(l+1,r-1);
		if(z == max(0, ((r-1) - (l+1) + 1))) z += 2;
	}

	vis[l][r] = vez;
	return dp[l][r] = max({x,y,z});
}

bool f(char x) {
	string v = {"AHIMOTUVWXY"};
	for(int i = 0; i < v.size(); i++) if(x == v[i]) return 1;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	int tc; cin >> tc;
	while(tc--) {
		cin >> s;
		for(int i = 0; i < s.size(); i++) ok[i] = f(s[i]);
		n = s.size()-1;
		vez++;
		cout << solve(0,n) << endl;
	}
	return 0;
}

