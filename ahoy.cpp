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

vi st;
vector<ii> lazy;
int size;

void build(string& v, int id, int l, int r) {
	if (l == r) {
		st[id] = v[l] - '0';
	}
	else {
		int mid = avg(l, r);
		build(v, left(id), l, mid);
		build(v, right(id), mid + 1, r);
		st[id] = st[left(id)] + st[right(id)];
	}
}

void prop(int id, int l, int r) {
	int x, y;
	tie(x, y) = lazy[id];
	if (y >= 0) {
		if (x == 1) st[id] = r - l + 1;
		else if (x == 0) st[id] = 0;
		else {
			st[id] = r - l + 1 - st[id];
		}
		if (l != r) {
			if (lazy[left(id)].second != -1) prop(left(id), l, avg(l, r));
			if (lazy[right(id)].second!= -1) prop(right(id), avg(l, r) + 1, r);
			lazy[left(id)] = lazy[id];
			lazy[right(id)] = lazy[id];
		}
		lazy[id] = {0, -1};
	}
}
/*@*/
// void propAll(int id, int l, int r) {
// 	prop(id, l, r);
// 	if (l == r) return;
// 	int mid = avg(l, r);
// 	propAll(left(id), l, mid);
// 	propAll(right(id), mid + 1, r);
// }
/*@*/
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
		lazy[id] = {val, 0};
		prop(id, l, r);
	}
	else {
		int mid = avg(l, r);
		update(left(id), a, b, l, mid, val);
		update(right(id), a, b, mid + 1, r, val);
		st[id] = st[id << 1] + st[id << 1 | 1];
	}
}
/*@*/
// string buffer;
// void printBase(int id, int l, int r ) {
// 	if (l == r) {
// 		buffer[l] = st[id] + '0';
// 	}
// 	else {
// 		int mid = avg(l, r);
// 		printBase(left(id), l, mid);
// 		printBase(right(id), mid + 1, r);
// 	}
// }
// void print() {
// 	buffer.clear();
// 	buffer.resize(size, '-');
// 	propAll(1, 0, size - 1);
// 	printBase(1, 0, size - 1);
// 	cout << buffer << endl;
// }
/*@*/
int main() {
	ios_base::sync_with_stdio(false);

	int t, cs = 1;
	cin >> t;
	loop(t) {
		string s = "", y;
		int m;
		cin >> m;
		loop(m) {
			int q;
			cin >> q >> y;
			loop(q) {
				s += y;
			}
		}
		size = s.size();
		st.clear(), st.resize(4 * size + 10);
		lazy.clear(), lazy.resize(4 * size + 10, {0, -1});
		build(s, 1, 0, size - 1);

		int q, a, b;
		char c;
		cin >> q;
		cout << "Case " << cs++ << ":" << endl;
		int qu = 1;
		loop(q) {
			cin >> c >> a >> b;
			if (c == 'S') {
				cout << "Q" << qu++ << ": ";
				cout << query(1, a, b, 0, size - 1) << endl;
			}
			// else if (c == 'P') {
			// 	propAll(1, 0, size - 1);
			// 	print();
			// }
			else {
				update(1, a, b, 0, size - 1, (c == 'F' ? 1 : (c == 'E' ? 0 : -1)));
			}
		}
	}
	return 0;
}
