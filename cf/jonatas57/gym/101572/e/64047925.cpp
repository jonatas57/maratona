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
typedef tuple<int,int,int> ti;
typedef vector<ti> vti;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 505;
int mat[T][T];
bool vis[T][T];
int mov[8][2] = { {1,0}, {0,1}, {-1,0}, {0,-1}, {1,-1}, {-1,1}, {1,1}, {-1,-1} };
int a,b;
int n,m;

bool isIn(int x, int y) {
	return (x >= 1 and x <= n and y >= 1 and y <= m);
}

priority_queue<ti, vector<ti>> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;

	for(int i = 1; i <= n; i++)
		for(int j = 1;j <= m; j++) {
			cin >> mat[i][j];
			if(mat[i][j] >= 0) mat[i][j] = 0;
			else mat[i][j] = abs(mat[i][j]);
		}

	cin >> a >> b;
	vis[a][b] = 1;
	pq.emplace(mat[a][b],a,b);
	ll ans = 0;

	while(!pq.empty()) {
		ti at = pq.top();
		pq.pop();
		int x,y,z;
		tie(z,x,y) = at;
		ans += (ll)z;

		for(int k = 0; k < 8; k++) {
			int xx = x + mov[k][0];
			int yy = y + mov[k][1];
			if(isIn(xx,yy) and !vis[xx][yy]) {
				pq.emplace(min(z,mat[xx][yy]), xx,yy);
				vis[xx][yy] = 1;
			}
		}
	}

	cout << ans << endl;

	return 0;
}

