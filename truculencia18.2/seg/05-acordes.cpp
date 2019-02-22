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

int NULO[11] = {0};
#define T                  100000
#define N                  4 * T + 10
#define freq(x)            x[9]
#define start(x)           x[10]
#define mod(x)             if (x >= 9) x -= 9

int st[N][11], lazy[N];
void sum(int x[], int y[], int z[]) {
	int i = start(z), j = start(x), k = start(y), maxf = i;
	for (int c = 0;c < 9;c++) {
		z[i] = x[j] + y[k];
		if (z[i] >= z[maxf]) {
			maxf = i;
		}
    mod(++i);
    mod(++j);
    mod(++k);
	}
  freq(z) = maxf + start(z);
  mod(freq(z));
}
void build(vi& v, int id, int l, int r) {
	if (l == r) {
		memset(st[id], 0, 11);
		st[id][v[l]]++;
		freq(st[id]) = v[l];
		lazy[id] = 0;
	}
	else {
		int mid = avg(l, r);
		build(v, left(id), l, mid);
		build(v, right(id), mid + 1, r);
		sum(st[left(id)], st[right(id)], st[id]);
	}
}

void prop(int id, int l, int r) {
  if (lazy[id]) {
    mod(lazy[id]);
		start(st[id]) = start(st[id]) + 9 - lazy[id];
		freq(st[id]) += lazy[id];
    mod(start(st[id]));
		mod(freq(st[id]));
    if (l != r) {
      lazy[left(id)] += lazy[id];
      lazy[right(id)] += lazy[id];
    }
    lazy[id] = 0;
  }
}
int* query(int id, int l, int r, int ql, int qr) {
	prop(id, l, r);
	if (l > qr or r < ql) return NULO;
	if (l >= ql and r <= qr) return st[id];
	int mid = avg(l, r);
	int *x = query(left(id), l, mid, ql, qr);
  int *y = query(right(id), mid + 1, r, ql, qr);
  int ans[11] = {0};
	sum(x, y, ans);
	return ans;
}

void update(int id, int l, int r, int a, int b, int v) {
  prop(id, l, r);
  if (l > b or r < a) return;
	if (l >= a and r <= b) {
    lazy[id] = v;
    prop(id, l, r);
  }
	else {
    int mid = avg(l, r);
    update(left(id), l, mid, a, b, v);
    update(right(id), mid + 1, r, a, b, v);
  	sum(st[left(id)], st[right(id)], st[id]);
  }
}
void print(int id, int l, int r) {
	prop(id, l, r);
	if (l == r) {
		printf("%d\n", freq(st[id]));
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
	vi v(n, 1);
	build(v, 1, 0, n - 1);
	int a, b;
	loop(q) {
		scanf("%d %d", &a, &b);
		int f = query(1, 0, n - 1, a, b)[9];
		update(1, 0, n - 1, a, b, f);
	}
	print(1, 0, n - 1);
	return 0;
}
