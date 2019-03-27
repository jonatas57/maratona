#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define MAX                100000
#define N                  4 * MAX + 10
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define ceach(x, s)        for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2

struct node {
	int id;
	vector<node*> ch;
	node(int i) : id(i) {}
	void add(node* x) {
		ch.push_back(x);
	}
};
vector<node*> nodes;

int lca(int r, int a, int b, int x = 0) {
	if (r == a || r == b) return r;
	bool l = false;
	int ans, aux;
	each(c, nodes[r]->ch) {
		if ((aux = lca(c->id, a, b))) {
			if (l) return r;
			l = true;
			ans = aux;
		}
	}
	if (l)  return ans;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		int n, m, q, x, root;
		cin >> n;
		nodes.resize(n + 1);
		root = n * (n + 1) / 2;
		rep(1, n + 1, 1) {
			nodes[i] = new node(i);
		}
		rep(1, n + 1, 1) {
			cin >> m;
			vloop(j, m) {
				cin >> x;
				root -= x;
				nodes[i]->add(nodes[x]);
			}
		}
		cin >> q;
		cout << "Case " << i + 1 << ":" << endl;
		int a, b;
		loop(q) {
			cin >> a >> b;
			cout << lca(root, a, b) << endl;
		}
	}
	return 0;
}

