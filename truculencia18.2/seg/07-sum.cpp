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
#define avg(x, y)          x + (y - x) / 2
#define left(x)            x << 1
#define right(x)           x << 1 | 1

#define T                  100000
#define N                  4 * T + 10

ii st[N];

ii func(ii a, ii b) {
	vi aux = {a.first, a.second, b.first, b.second};
	sort(aux.begin(), aux.end());
	return {aux[2], aux[3]};
}
void build(vi& v, int id, int l, int r) {
	if (l == r) {
		st[id] = {v[l], -1};
	}
	else {
		int mid = avg(l, r);
		build(v, left(id), l, mid);
		build(v, right(id), mid + 1, r);
		st[id] = func(st[left(id)], st[right(id)]);
	}
}
void update(int id, int l, int r, int pos, int v) {
	if (l == r) {
		st[id].first = v;
	}
	else {
		int mid = avg(l, r);
		if (pos <= mid) {
			update(left(id), l, mid, pos, v);
		}
		else {
			update(right(id), mid + 1, r, pos, v);
		}
		st[id] = func(st[left(id)], st[right(id)]);
	}
}
ii query(int id, int l, int r, int a, int b) {
	if (l > b or r < a) return {-1, -1};
	if (l >= a and r <= b) return st[id];
	int mid = avg(l, r);
	return func(query(left(id), l, mid, a, b), query(right(id), mid + 1, r, a, b));
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	int n, q, a, b;
	char c;
	scanf("%d", &n);
	vi x(n);
	loop(n) {
		scanf("%d", &x[i]);
	}
	build(x, 1, 0, n - 1);
	scanf("%d\n", &q);
	loop(q) {
		scanf("%c %d %d\n", &c, &a, &b);
		if (c == 'U') {
			update(1, 0, n - 1, a - 1, b);
		}
		else {
			ii p = query(1, 0, n - 1, a - 1, b - 1);
			printf("%d\n", p.first + p.second);
		}
	}
	return 0;
}
