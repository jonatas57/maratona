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

vector<vi> st;
void build(vi& v, int id, int l, int r) {
	if (l == r) st[id] = {v[l]};
	else {
		int mid = avg(l, r);
		build(v, id << 1, l, mid);
		build(v, id << 1 | 1, mid + 1, r);
		st[id].resize(r - l + 1);
		merge(iter(st[id << 1]), iter(st[id << 1 | 1]), st[id].begin());
	}
}
void init(vi& v) {
	int n = v.size();
	st.resize(4 * n + 10);
	build(v, 1, 0, n - 1);
}

int query(int id, int l, int r, int a, int b, int val) {
	if (r < a or l > b) return 0;
	if (a <= l and r <= b) {
		return lower_bound(iter(st[id]), val) - st[id].begin();
	}
	int mid = avg(l, r);
	return query(id << 1, l, mid, a, b, val) + query(id << 1 | 1, mid + 1, r, a, b, val);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, q;
	cin >> n >> q;
	vi c(n), last(n + 1, -1), a(n);
	loop(n) {
		cin >> c[i];
		a[i] = last[c[i]];
		last[c[i]] = i;
	}
	init(a);
	int l, r;
	loop(q) {
		cin >> l >> r;
		cout << query(1, 0, n - 1, l - 1, r - 1, l - 1) << endl;
	}
	return 0;
}

