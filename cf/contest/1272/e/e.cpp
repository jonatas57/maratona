#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;
 
#define INF                0x3f3f3f3f
#define INFLL              0x3f3f3f3f3f3f3f3f
#define each(x, s)         for(auto& x : s)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"
 
const ll mod = 1000000007;
 
int n;
vi a;
vector<vi> par;
vector<vb> vis;
 
int query(int i, int p, bool force = true) {
	if (i < 0 or i >= n or vis[i][p]) return INF;
	if (par[i][p] != INF and not force) return par[i][p];
	vis[i][p] = true;
	for (int j = -1;j < 2;j += 2) {
		int x = query(i + j * a[i], p, false);
		if (x >= 0 and x < INF) {
			par[i][p] = min(par[i][p], x + 1);
		}
	}
	vis[i][p] = false;
	return par[i][p];
}
 
int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
	int x;
	cin >> n;
	loop(n) {
		cin >> x;
		a.push_back(x);
		par.emplace_back(vi(2, INF));
		vis.emplace_back(vb(2, false));
		par[i][a[i] & 1] = 0;
	}
	loop(n) {
		int p, x = query(i, p = (a[i] + 1) & 1);
		if (par[i][p] == INF) x = par[i][p] = -1;
		cout << x << " ";
	}
	cout << endl;
	return 0;
}
