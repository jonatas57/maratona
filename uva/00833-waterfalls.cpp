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
#define endl               "\n"

struct uf {
	vi id, sz, gs;
	uf(int x) {
		id.resize(x);
		sz.resize(x, 1);
		gs.resize(x, INF);
		loop(x) id[i] = i;
	}
	int find(int x) {
		return x == id[x] ? x : id[x] = find(id[x]);
	}
	void join(int a, int b) {
		a = find(a);
		b = find(b);
		if (a == b) return;
		if (a > b) swap(a, b);
		id[a] = b;
		sz[b] += sz[a];
		gs[b] = min(gs[a], gs[b]);
	}
	void setVal(int i, int x) {
		i = find(i);
		gs[i] = x;
	}
	int getVal(int i) {
		i = find(i);
		return gs[i];
	}
};

int cnt = 0;
struct point {
	int id;
	double x, y;
	point(double x = 0, double y = 0) : id(cnt), x(x), y(y) {}
	point operator-(point p) {
		return point (x - p.x, y - p.y);
	}
	bool operator<(const point& p) const {
		return x == p.x ? y < p.y : x < p.x;
	}
};

struct line {
	double a, b, c;
	int low, high;
	line(point p, point q) {
		if (p.y > q.y) swap(p, q);
		low = p.id;
		high = p.id;
		point del = q - p;
		a = del.y;
		b = -del.x;
		c = -(a * q.x + b * q.y);
	}
	double operator()(int x) {
		return -(a * x + c) / b;
	}
};

vector<line> ls;
int lssize;
vb used;
vector<point> ps;
typedef tuple<point, int, bool> tp;

int search(set<int>& at, point& p) {
	int ans = -1;
	double val = -1;
	each(x, at) {
		double aux = ls[x](p.x);
		if (aux < p.y and aux > val) {
			val = aux;
			ans = x;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		if (i) cout << endl;
		ls.clear();
		ps.clear();
		used.clear();

		int m, n, x1, y1, x2, y2;
		cin >> n;
		vector<tp> sl;
		loop(n) {
			cin >> x1 >> y1 >> x2 >> y2;
			point p(x1, y1);cnt++;
			point q(x2, y2);cnt++;
			ls.emplace_back(p, q);
			ps.push_back(p);
			ps.push_back(q);
			sl.emplace_back(p, i, y1 < y2);
			sl.emplace_back(q, i, y1 > y2);
		}
		lssize = ls.size();
		cin >> m;
		loop(m) {
			cin >> x1 >> y1;
			point p(x1, y1);cnt++;
			ps.push_back(p);
			sl.emplace_back(p, INF, true);
		}
		sort(iter(sl));
		used.resize(sl.size(), false);
		int lid;
		bool low;
		point p;
		set<int> at;
		uf unifind(2 * n + m);
		each(tup, sl) {
			tie(p, lid, low) = tup;
			if (low) {
				int next = search(at, p);
				if (next == -1) {
					unifind.setVal(p.id, p.x);
				}
				else {
					unifind.join(p.id, ls[next].low);
				}
			}
			if (lid != INF) {
				if (used[lid]) {
					at.erase(lid);
				}
				else {
					at.insert(lid);
					used[lid] = true;
				}
			}
		}
		loop(m) {
			cout << unifind.getVal(2 * n + i) << endl;
		}
	}
	return 0;
}
