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

#define T                  1000
#define SIZE               4 * T + 10

int st[SIZE] = {0}, lazy[SIZE];

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
/*@*/
void propAll(int id, int l, int r) {
	prop(id, l, r);
	if (l == r) return;
	int mid = avg(l, r);
	propAll(left(id), l, mid);
	propAll(right(id), mid + 1, r);
}
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
/*@*/
string buffer;
void printBase(int id, int l, int r ) {
	if (l == r) {
		buffer[l] = st[id] + '0';
	}
	else {
		int mid = avg(l, r);
		printBase(left(id), l, mid);
		printBase(right(id), mid + 1, r);
	}
}
void print() {
	buffer.clear();
	buffer.resize(SIZE, '-');
	propAll(1, 0, SIZE - 1);
	printBase(1, 0, SIZE - 1);
	cout << buffer << endl;
}
/*@*/

struct pirates {
	vector<char*> pir;
	vector<int> x;
	int qtd;

	pirates() : qtd(0) {x.pb(0);}
	void insert(int n, char* s) {
		cout << __LINE__ << endl;
		pir.pb(s);
		cout << __LINE__ << endl;
		x.pb(x[++qtd] + n * sizeof(s) / sizeof(char));
		cout << __LINE__ << endl;
	}
	int getChar(int i) {
		cout << __LINE__ << endl;
		int j = binSearch(1, qtd, i);
		cout << j << endl;
		cout << __LINE__ << endl;
		int aux = j;
		cout << __LINE__ << endl;
		return pir[j][aux] - '0';
	}
	int binSearch(int l, int r, int val) {
		cout << __LINE__ << endl;
		if (l == r) return l;
		cout << __LINE__ << endl;
		int mid = avg(l, r);
		cout << __LINE__ << endl;
		if (val >= x[mid - 1] && val < x[mid]) {
			cout << __LINE__ << endl;
			return mid;
		}
		else if (val < x[mid - 1]) {
			cout << __LINE__ << endl;
			return binSearch(l, mid, val);
		}
		else return binSearch(mid + 1, r, val);
	}
};

int main() {
	pirates p;
	// int t, cs = 1;
	// scanf("%d", &t);
	// loop(t) {
		// string s = "";
		char *y;
		int m;
		scanf("%d\n", &m);
		loop(m) {
			int q;
			scanf("%d\n", &q);
			scanf("%s\n", &y);
			// loop(q) {
			// 	s += string(y);
			// }
			p.insert(q, y);
		}
		while(cin >> m) {
			cout << p.getChar(m) << endl;
		}
	// 	int size = s.size();
	// 	memset(st, 0, sizeof(st));
	// 	memset(lazy, INF, sizeof(lazy));
	// 	build(s, 1, 0, size - 1);
	//
	// 	int q, a, b;
	// 	char c;
	// 	scanf("%d", &q);
	// 	printf("Case %d:\n", cs++);
	// 	int qu = 1;
	// 	loop(q) {
	// 		scanf("\n%c %d %d", &c, &a, &b);
	// 		if (c == 'S') {
	// 			printf("Q%d: ", qu++);
	// 			printf("%d\n", query(1, a, b, 0, size - 1));
	// 		}/*@*/
	// 		else if (c == 'P') {
	// 			propAll(1, 0, SIZE - 1);
	// 			print();
	// 		}/*@*/
	// 		else {
	// 			update(1, a, b, 0, size - 1, (c == 'F' ? 1 : (c == 'E' ? 0 : -1)));
	// 		}
	// 	}
	// }
	return 0;
}
