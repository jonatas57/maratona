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

const int T = 505;
vector<int> g[T];
int idade[T];
int ondeesta[T];
int quemesta[T];
int vis[T];
int tmp[T];
int n,m,q,vez;

int dfs(int at, int ori) {
	int ans;
	vis[at] = vez;
	if(ori != at) ans = idade[quemesta[at]];
	else ans = INF;

	for(int v : g[at]) { 
		if(vis[v] != vez) dfs(v,ori);
		ans = min(ans,tmp[v]);
	}

	return tmp[at] = ans;
}


 
int main() {
    ios_base::sync_with_stdio(false);
	cin >> n >> m >> q;
	int x,y;
	for(int i = 1; i <= n; i++) {
		cin >> x;
		idade[i] = x;
		quemesta[i] = i;
		ondeesta[i] = i;
	}
	
	for(int i = 0; i < m; i++) {
		cin >> x >> y;	
		g[y].pb(x);
	}

	char op;

	for(int i = 0; i < q; i++) {   
		cin >> op >> x;
		if(op == 'T') {
			cin >> y;
			swap(quemesta[ondeesta[x]], quemesta[ondeesta[y]]);
			swap(ondeesta[x], ondeesta[y]);
			//swap(idade[x],idade[y]);
		} else {
			vez++;
			int ans = dfs(ondeesta[x],ondeesta[x]);
			if(ans == INF) cout << "*" << endl;
			else cout << ans << endl;
		}
	}
    
    return 0;
}

