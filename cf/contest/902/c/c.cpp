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

struct graph {
	int size;
	vector<list<int>> adj;
	graph(int n) : size(n), adj(n) {}
	void addEdge(int a, int b) {
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int h;
	cin >> h;
	vi a(h + 1);
	int n = 0;
	loop(h + 1) cin >> a[i], n += a[i];
	vi f(n, 0), g(n, 0);
	bool equal = true;
	for (int i = 1, j = 1;i <= h;i++) {
		int x = j;
		vloop(k, a[i]) {
			f[j] = g[j] = x;
			j++;
		}
		if (equal and a[i - 1] > 1 and a[i] > 1) {
			g[j - 1] = x - 1;
			equal = false;
		}
	}
	if (equal) cout << "perfect" << endl;
	else {
		cout << "ambiguous" << endl;
		each(x, f) cout << x << " ";
		cout << endl;
		each(x, g) cout << x << " ";
		cout << endl;
	}
	return 0;
}

