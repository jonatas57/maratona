#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<ll>         vll;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define each(x, s)         for(auto& x : s)
#define ceach(x, s)        for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define pb                 push_back
#define T                  100000
#define N                  4 * T + 10
#define avg(x, y)          x + (y - x) / 2
#define left(x)            x << 1
#define right(x)           x << 1 | 1

#define T                  100000
#define N                  4 * T + 10
#define mod(x)             if (x >= 9) x -= 9; else if(x < 0) x += 9

struct tecla {
	int count[9];
	int freq, start;

	tecla(bool p = true) : freq(p), start(0) {
		memset(count, 0, 9);
		if (p) {
			count[1] = 1;
		}
	}
	void sum(tecla& x, tecla& y) {
		int m = 0, mf = 0;
		loop(9) {
			int t = i + start;
			mod(t);
			count[t] = x[i] + y[i];
			if (m <= count[t]) {
				m = count[t];
				mf = i + 9 - start;
			}
		}
		freq = mf;
		mod(freq);
	}
	int& operator[](int x) {
		x += start;
		mod(x);
		return count[x];
	}
	void operator+=(int x) {
		freq += x;
		start -= x;
		mod(freq);
		mod(start);
	}
} null(0);

tecla st[N];
int lazy[N];

void build(int id, int l, int r) {
	if (l == r) {
		lazy[id] = 0;
	}
	else {
		int mid = avg(l, r);
		build(left(id), l, mid);
		build(right(id), mid + 1, r);
		st[id].sum(st[left(id)], st[right(id)]);
	}
}
void prop(int id, int l, int r) {
	if (lazy[id]) {
		lazy[id] %= 9;
		st[id] += lazy[id];
		if (l != r) {
			lazy[left(id)] += lazy[id];
			lazy[right(id)] += lazy[id];
		}
		lazy[id] = 0;
	}
}
tecla query(int id, int l, int r, int a, int b) {
	prop(id, l, r);
	if (l > b or r < a) return null;
	if (l >= a and r <= b) return st[id];
	int mid = avg(l, r);
	tecla x, y = query(left(id), l, mid, a, b), z = query(right(id), mid + 1, r, a, b);
	x.sum(y, z);
	return x;
}
void update(int id, int l, int r, int a, int b, int v) {
	prop(id, l, r);
	if (l > b or r < a) return;
	if (l >= a and r <= b) {
		lazy[id] = v;
		prop(id, l, r);
		return;
	}
	int mid = avg(l, r);
	update(left(id), l, mid, a, b, v);
	update(right(id), mid + 1, r, a, b, v);
	st[id].sum(st[left(id)], st[right(id)]);
}
void print(int id, int l, int r) {
	prop(id, l, r);
	if (l == r) {
		printf("%d\n", st[id].freq);
	}
	else {
		int mid = avg(l, r);
		print(left(id), l, mid);
		print(right(id), mid + 1, r);
	}
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	int n, q;
	scanf("%d %d", &n, &q);
	build(1, 0, n - 1);
	int a, b;
	loop(q) {
		scanf("%d %d", &a, &b);
		update(1, 0, n - 1, a, b, query(1, 0, n - 1, a, b).freq);
	}
	print(1, 0, n - 1);
	return 0;
}
