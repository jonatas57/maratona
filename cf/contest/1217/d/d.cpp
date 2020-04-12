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
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()

struct graph {
	int size;
	vector<pair<ii, bool>> es;
	graph(int n) : size(n) {}
	void addEdge(int a, int b) {
		es.emplace_back(ii(a, b), false);
	}
};



int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	int a, b;
	graph g(n);
	loop(m) cin >> a >> b, g.addEdge(a, b);
	int k;
	vi ans;
	tie(ans, k) = color(g);
	cout << k << endl;
	each(x, ans) cout << x << " "; cout << endl;
	return 0;
}
