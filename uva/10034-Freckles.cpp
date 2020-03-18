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
	vector<tuple<double, int, int>> adj;
	graph(int n) : size(n) {}
	void addEdge(int a, int b, double c) {
		adj.emplace_back(c, a, b);
	}
};

vi id, sz;
void init(int x) {
	id.resize(x);
	sz.assign(x, 1);
	loop(x) id[i] = i;
}
int find(int x) { return x == id[x] ? x : id[x] = find(id[x]); }
bool join(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	if (a > b) swap(a, b);
	id[a] = b;
	sz[b] += sz[a];
	return true;
}

struct point {
	double x, y;
	point(double x, double y) : x(x), y(y) {}
	point operator-(point p) {
		return point(x - p.x, y - p.y);
	}
};
double dist(point a, point b) {
	point del = a - b;
	return sqrt(del.x * del.x + del.y * del.y);
}

double kruskall(graph& g) {
	init(g.size);
	double w, ans = 0;
	int u, v;
	sort(iter(g.adj));
	each(p, g.adj) {
		tie(w, u, v) = p;
		if (join(u, v)) ans += w;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		if (i) cout << endl;
		int n;
		cin >> n;
		graph g(n);
		vector<point> ps;
		loop(n) {
			double a, b;
			cin >> a >> b;
			ps.emplace_back(a, b);
			vloop(j, i) {
				g.addEdge(i, j, dist(ps[i], ps[j]));
			}
		}
		cout << fixed << setprecision(2) << kruskall(g) << endl;
	}
	return 0;
}

