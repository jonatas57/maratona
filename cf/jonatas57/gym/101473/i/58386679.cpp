#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define cc(x)	cout << #x << " = " << x << endl
#define ok		cout << "ok" << endl
#define MAX                100000
#define N                  4 * MAX + 10
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define ceach(x, s)        for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define endl '\n'

typedef long long ll;
typedef pair<int,int> ii;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 1e3 + 5;
vector<int> v;
int nxt1[T]; 
int nxt2[T];
int dp[T];
int n,c,t1,t2;

int solve(int at) {
	if(at == n) return 0;
	if(dp[at] != -1) return dp[at];
	dp[at] = min(solve(nxt1[at]) + t1, solve(nxt2[at]) + t2);
	return dp[at];
}


int main() {
    ios_base::sync_with_stdio(false);
	memset(dp, -1, sizeof dp);
	cin >> n >> c >> t1 >> t2;
	int x;

	for(int i = 0; i < n; i++) {
		cin >> x;
		v.pb(x);
	}

	for(int i = 0; i < n; i++) { 
		nxt1[i] = lower_bound(v.begin(), v.end(), v[i] + t1+1) - v.begin();
		nxt2[i] = lower_bound(v.begin(), v.end(), v[i] + t2+1) - v.begin();
	}

	cout << solve(0) << endl;
    
    return 0;
}

