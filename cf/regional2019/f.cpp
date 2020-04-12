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

int left(int x) { return x << 1; }
int right(int x) { return x << 1 | 1; }

vi st;

void update(int id, int l, int r, int a, int b, int val) {
	if (l > b or r < a) return;
	if (l >= a and r <= b and (st[id] or val != 1)) st[id] += val;
	else {
		int mid = avg(l, r);
		update(left(id), l, mid, a, b, val);
		update(right(id), mid + 1, r, a, b, val);
	}
}

int query(int id, int l, int r, int a, int b) {
	if (l > b or r < a) return 0;
	if (l >= a and r <= b) {
		if (st[id]) return r - l + 1;
		else if (l == r) return 0;
	}
	int mid = avg(l, r);
	return query(left(id), l, mid, a, b) + query(right(id), mid + 1, r, a, b);
}

vector<tuple<int, int, int, int>> rivers;
tuple<int, int, int, int> nlog;
int p, n, maxy, area;

tuple<int, int, int, int> intersect(tuple<int, int, int, int> a, tuple<int, int, int, int> b) {
	int x1, x2, x3, x4, y1, y2, y3, y4;
	tie(x1, y1, x2, y2) = a;
	tie(x3, y3, x4, y4) = b;
	return make_tuple(max(x1, x3), max(y1, y3), min(x2, x4), min(y2, y4));
}

int f(int r) {
	vector<tuple<int, int, int, int>> recs;
	int x1, x2, y1, y2, val;
	each(river, rivers) {
		tie(x1, y1, x2, y2) = river;
		x1 -= r, x2 += r, y1 -= r, y2 += r;
		tie(x1, y1, x2, y2) = intersect(nlog, make_tuple(x1, y1, x2, y2));
		recs.emplace_back(x1, y1, y2, -1);
		recs.emplace_back(x2, y1, y2, 1);
	}
	sort(iter(recs));
	int ans = 0, lastx = 0, lastq = 0;
	each(rec, recs) {
		tie(x1, y1, y2, val) = rec;
		ans += (x1 - lastx) * lastq;
		update(1, 1, maxy, y1, y2, val);
		lastq = query(1, 1, maxy, 1, maxy);
		lastx = x1;
	}
	return ans;
}

int bb(int l, int r) {
	if (l == r) return l;
	int mid = avg(l, r);
	int x = 100 * f(mid) / area;
	return x >= p ? bb(l, mid) : bb(mid + 1, r);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	cin >> n;
	int x1, y1, x2, y2;
	loop(n) {
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 > x2 or y1 > y2) swap(x1, x2), swap(y1, y2);
		rivers.emplace_back(x1, y1, x2, y2);
	}
	cin >> p;
	cin >> x1 >> y1 >> x2 >> y2;
	maxy = y2;
	st.resize(4 * maxy + 10, 0);
	nlog = make_tuple(x1, y1, x2, y2);
	area = (x2 - x1) * (y2 - y1);
	cout << bb(0, y2) << endl;
	return 0;
}


