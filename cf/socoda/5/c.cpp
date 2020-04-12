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

int ans = 0;
struct graph {
	int size;
	vi par, h, l, r;
	graph(int n) : size(n), par(n, -1), h(n, 0), l(n, -1), r(n, -1) {}
	int addChild(int p, int c) {
		par[c] = p;
		int last = c;
		h[c] = 1;
		c = p;
		while (c != -1) {
			if (l[c] != last and getH(r[c]) < h[last]) r[c] = last;
			if (getH(l[c]) < getH(r[c])) swap(l[c], r[c]);
			h[c] = max(h[c], getH(l[c]) + 1);
			ans = max(ans, getH(l[c]) + getH(r[c]));
			last = c;
			c = par[c];
		}
		return ans;
	}
	int getH(int x) {
		return x == -1 ? 0 : h[x];
	}
};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	int p;
	graph g(n);
	loop(n - 1) {
		cin >> p;
		cout << g.addChild(p - 1, i + 1) << " ";
	}
	cout << endl;
	return 0;
}

