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
typedef vector<ii> vii;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

const int T = 305;

int mat[T][T];
int nmat[T][T];

int n,m;
vii col;
vii lin;
int trocas;

void build(int dest, int from) {
	for(int i = 0; i < n; i++) nmat[i][dest] = mat[i][from];
}
	

int main() {
    ios_base::sync_with_stdio(false);
	cin >> n >> m;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			cin >> mat[i][j];

	for(int j = 0; j < m; j++) {
		col.eb(j,INF);
		for(int i = 0; i < n; i++) {
			if(mat[i][j] < col.rbegin()->se) col.rbegin()->se = mat[i][j];
		}
	}

	for(int i = 0; i < m; i++) {
		for(int j = i; j < m; j++) {
			if(col[j].se == i+1) {
				if(j != i) {
					swap(col[i],col[j]);
					trocas++;
				}
				break;
			}
		}
	}

	for(int i = 1; i < m; i++) if(col[i].se != col[i-1].se+1) {
		cout << "*" << endl;
		return 0;
	}


	for(int i = 0; i < m; i++)  {
		build(i,col[i].fi);
	}

	for(int i = 0; i < n; i++)
		for(int j = 1; j < m; j++)
			if(nmat[i][j-1]+1 != nmat[i][j]) {cout << "*" << endl; return 0;}


	for(int i = 0; i < n; i++) {
		lin.eb(0,INF);
		for(int j = 0; j < m; j++) {
			if(mat[i][j] < lin.rbegin()->se) lin.rbegin()->se = mat[i][j];
		}
	}			


	for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
			if(lin[j].se == (i*m)+1) {
				if(j != i) {
					swap(lin[i],lin[j]);
					trocas++;
				}
				break;
			}
		}
	}

	cout << trocas << endl;
    
    return 0;
}

