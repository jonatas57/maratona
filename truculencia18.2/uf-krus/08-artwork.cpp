#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define each(x, s)         for(auto& x : s)
#define ceach(x, s)        for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define pb                 push_back

#define N                  1000000

int n, m;

int id[N], sz[N];
void makeset() {
	loop(N) {
		id[i] = i;
		sz[i] = 1;
	}
}
int find(int x) {
	if (x == id[x]) return x;
	return id[x] = find(id[x]);
}
bool join(int x, int y) {
	if (x < 0 or y < 0) return false;
	int a = find(x), b = find(y);
	if (a == b) return false;
	if (sz[a] > sz[b]) swap(a, b);
	id[a] = id[b];
	sz[b] += sz[a];
	return true;
}

struct node {
	int x, y;
	vector<node*> adj;
	bool active;

	node(int x, int y) : x(x), y(y), active(true) {
		adj.resize(4, nullptr);
	}
	void addEdge(node* p, int d) {
		adj[d] = p;
		p->adj[d ^ 2] = this;
	}
	operator int() {
		return active ? x * 1000 + y : -1;
	}
	operator bool() {
		return active;
	}
};
vector<vector<node*>> mapa;

int cnt;
node* removeNode(node* x) {
	if (x and x->active) {
		x->active = false;
		cnt--;
		return x;
	}
	return nullptr;
}
void newNode(int i, int j) {
	if (mapa[i][j]) mapa[i][j]->active = true;
	else mapa[i][j] = new node(i, j);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	int q;
	cin >> n >> m >> q;
	cnt = n * m;

	mapa.resize(m, vector<node*>(n, nullptr));
	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			newNode(i, j);
			if (i > 0) mapa[i][j]->addEdge(mapa[i - 1][j], 0);
			if (j > 0) mapa[i][j]->addEdge(mapa[i][j - 1], 3);
		}
	}

	list<list<node*>> removes;
	int a, b, c, d;
	loop(q) {
		list<node*> aux;
		cin >> a >> b >> c >> d;
		a--, b--, c--, d--;
		if (a > c) swap(a, c);
		if (b > d) swap(b, d);
		if (a == c) {
			for (int i = b;i <= d;i++) {
				node *x = removeNode(mapa[i][a]);
				if (x) aux.push_front(x);
			}
		}
		else {
			for (int i = a;i <= c;i++) {
				node *x = removeNode(mapa[b][i]);
				if (x) aux.push_front(x);
			}
		}
		removes.push_front(aux);
	}
	makeset();
	for (int i = 0;i < m;i++) {
		for (int j = 0;j < n;j++) {
			if (i > 0) if(join(*mapa[i][j], *mapa[i - 1][j])) cnt--;
			if (j > 0) if(join(*mapa[i][j], *mapa[i][j - 1])) cnt--;
		}
	}
	list<int> ans;
	ans.push_front(cnt);

	loop(q - 1) {
		list<node*> aux;
		aux = removes.front();removes.pop_front();
		each(nd, aux) {
			nd->active = true;
			cnt++;
			each(p, nd->adj) {
				if (p) {
					if (join(*nd, *p)) cnt--;
				}
			}
		}
		ans.push_front(cnt);
	}

	each(x, ans) {
		cout << x << endl;
	}
	return 0;
}
