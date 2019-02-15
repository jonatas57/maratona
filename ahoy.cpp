#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;

#define INF                0x3f3f3f3f
#define each(x, s)         for(auto& x : s)
#define ceach(x, s)        for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define pb                 push_back
#define avg(x, y)          x + (y - x) / 2
#define left(x)            x << 1
#define right(x)           x << 1 | 1

#define N                  1024000
#define SIZE               4 * N + 10

int st[SIZE] = {0}, lazy[SIZE];

void build(string& s, int id, int l, int r) {
	if (l == r) {
		st[id] = s[l] - '0';
	}
	else {
		int mid = avg(l, r);
		build(s, left(id), l, mid);
		build(s, right(id), mid + 1, r);
		st[id] = st[left(id)] + st[right(id)];
	}
}
void propaux(int& x, int y) {
	if (y == 0 || y == 1) x = y;
	else if (y == -1) {
		if (x == INF) x = y;
		else if (x == -1) x = INF;
		else x ^= 1;
	}
}
void prop(int id, int l, int r) {
	if (lazy[id] <= 1) {
		if (lazy[id] == 1)      st[id] = r - l + 1;
		else if (lazy[id] == 0) st[id] = 0;
		else                    st[id] = r - l + 1 - st[id];

		if (l != r) {
			propaux(lazy[left(id)], lazy[id]);
			propaux(lazy[right(id)], lazy[id]);
		}
		lazy[id] = INF;
	}
}
int query(int id, int a, int b, int l, int r) {
	prop(id, l, r);
	if (a > r or b < l) return 0;
	if (l >= a and r <= b) return st[id];
	int mid = avg(l, r);
	return query(left(id), a, b, l, mid) + query(right(id), a, b, mid + 1, r);
}
void update(int id, int a, int b, int l, int r, int val) {
	prop(id, l, r);
	if (a > r or b < l) return;
	if (l >= a and r <= b) {
		lazy[id] = val;
		prop(id, l, r);
	}
	else {
		int mid = avg(l, r);
		update(left(id), a, b, l, mid, val);
		update(right(id), a, b, mid + 1, r, val);
		st[id] = st[id << 1] + st[id << 1 | 1];
	}
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
	int t;
	scanf("%d", &t);
	loop(t) {
		int m, q;
		char y[101];
		string s = "";
		scanf("%d", &m);
		loop(m) {;
			scanf("%d\n%s\n", &q, y);
			loop(q) {
				s += string(y);
			}
		}
		int size = s.size() - 1;
		memset(lazy, INF, SIZE);
		build(s, 1, 0, size);
		int o, a, b;
		printf("Case %d:\n", i + 1);
		scanf("%d\n", &o);
		char ch;
		int qu = 1;
		loop(o) {
			scanf("%c %d %d\n", &ch, &a, &b);
			if (ch == 'S') {
				printf("Q%d: %d\n", qu++, query(1, a, b, 0, size));
			}
			else {
				update(1, a, b, 0, size, (ch == 'F' ? 1 : (ch == 'E' ? 0 : -1)));
			}
		}
	}
	return 0;
}
