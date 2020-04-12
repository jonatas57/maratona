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

typedef tuple<int, int, int, int> tup;

dijkstra(vector<vi>& a, int n) {
	vector<vector<ii>> val(n, vector<ii>(n, {INF, INF}));
	vector<vb> visit(n, vb(n, false));
	priority_queue<tup, vector<tup>, greater<tup>> q;
	dist[0][0] = {calc(a[0][0], 2), calc(a[0][0], 5)};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	vector<vi> a(n, vi(n));
	dp.resize(n + 1, vector<ii>(n + 1, {-1, -1}));
	loop(n) {
		vloop(j, n) {
			cin >> a[i][j];
		}
	}
	ii ans = solve(n, n);
	cout << ans.first << endl;
	return 0;
}

