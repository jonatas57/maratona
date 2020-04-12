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

struct seg {
	vi st;
	int size;
	seg(vi& v, int n) : st(4 * n + 10) {
		size = n;
		build(v, 1, 0, n - 1);
	}
	void build(vi& v, int id, int l, int r) {
		if (l == r) st[id] = v[l];
		else {
			int mid = avg(l, r);
			build(v, id << 1, l, mid);
			build(v, id << 1 | 1, mid + 1, r);
			st[id] = min(st[id << 1], st[id << 1 | 1]);
		}
	}
	int query(int l, int r, int a, int b, int id = 1) {
		if (l > b or r < a) return INF;
		if (a >= l and b <= r) return st[id];
		int mid = avg(a, b);
		return min(query(l, r, a, mid, id << 1), query(l, r, mid + 1, b, id << 1 | 1));
	}
};

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		int n, m, k;
		cin >> n >> m >> k;
		vi a(n), pos;
		loop(n) cin >> a[i];
		loop(m) {
			pos.push_back(max(a[i], a[i + n - m]));
		}
		seg st(pos, m);
		int ans = 0;
		k = min(k, m - 1);
		loop(k + 1) {
			ans = max(ans, st.query(i, i + m - 1 - k, 0, m - 1));
		}
		cout << ans << endl;
	}
	return 0;
}

