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

#define left(id) id << 1
#define right(id) id << 1 | 1

vector<ll> lazy;
vector<pair<ll, bool>> st;

void build(vector<ll>& v, int id, int l, int r) {
	if (l == r) {
		st[id] = {v[l], true};
	}
	else {
		int mid = avg(l, r);
		build(v, left(id), l, mid);
		build(v, right(id), mid + 1, r);
		ll a, b;
		bool p, q;
		tie(a, p) = st[left(id)], tie(b, q) = st[right(id)];
		st[id] = {a + b, p and q and (a * (r - mid) == b * (mid - l + 1))};
	}
}

void prop(int id, int l, int r) {
	if (lazy[id]) {
		st[id] = {(ll)(r - l + 1) * lazy[id], true};
		if (l != r) {
			lazy[left(id)] = lazy[right(id)] = lazy[id];
		}
		lazy[id] = 0;
	}
}

void update(int id, int l, int r, int a, int b, ll val) {
	prop(id, l, r);
	if (l > b or r < a or a > b) return;
	if (l >= a and b >= r) {
		lazy[id] = val;
		prop(id, l, r);
	}
	else {
		int mid = avg(l, r);
		update(left(id), l, mid, a, b, val);
		update(right(id), mid + 1, r, a, b, val);
		ll a, b;
		bool p, q;
		tie(a, p) = st[left(id)], tie(b, q) = st[right(id)];
		st[id] = {a + b, p and q and (a * (r - mid) == b * (mid - l + 1))};
	}
}

ll query(int id, int l, int r, int a, int b) {
	prop(id, l, r);
	if (l > b or r < a or a > b) return 0;
	if (a == b and st[id].second) return st[id].first / (r - l + 1);
	if (l >= a and b >= r) return st[id].first;
	int mid = avg(l, r);
	return query(left(id), l, mid, a, b) + query(right(id), mid + 1, r, a, b);
}

int n;
int bbR(int l, int r, ll x) {
	if (l > r) return l;
	int mid = avg(l, r);
	if (query(1, 0, n - 1, mid, mid) < x) return bbR(mid + 1, r, x);
	return bbR(l, mid - 1, x);
}
int bbL(int l, int r, ll x) {
	if (l > r) return l;
	int mid = avg(l, r);
	if (query(1, 0, n - 1, mid, mid) < x) return bbL(l, mid - 1, x);
	return bbL(mid + 1, r, x);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	while(t--) {
		int q;
		cin >> n >> q;
		vector<ll> a(n), b(n);
		ll maxa = 0;
		ii maxi(0, 0);
		ll suma = 0;
		loop(n) {
			cin >> a[i];
			suma += a[i];
			if (maxa < a[i]) maxa = a[maxi.first = maxi.second = i];
			if (maxa == a[i]) maxi.second = i;
		}
		b[0] = a[0];
		b[n - 1] = a[n - 1];
		for (int i = 1;i < maxi.first;i++) b[i] = max(b[i - 1], a[i]);
		for (int i = n - 2;i >= maxi.first;i--) b[i] = max(b[i + 1], a[i]);
		st.resize(4 * n + 18);
		lazy.assign(4 * n + 18, 0);
		build(b, 1, 0, n - 1);
		char op;
		ll x, v;
		loop(q) {
			cin >> op;
			if (op == 'U') {
				cin >> x >> v;
				x--;
				ll na = a[x] + v;
				if (na > b[x]) {
					if (na > maxa) {
						int l = -1, r;
						if (x < maxi.first) {
							l = x;
							r = maxi.first - 1;
						}
						else if (x > maxi.second) {
							l = maxi.second + 1;
							r = x;
						}
						if (l != -1) update(1, 0, n - 1, l, r, maxa);
						update(1, 0, n - 1, x, x, na);
						maxa = na;
						maxi = {x, x};
					}
					else if (na == maxa) {
						maxi.first = min((ll)maxi.first, x);
						maxi.second = max((ll)maxi.second, x);
						update(1, 0, n - 1, maxi.first, maxi.second, maxa);
					}
					else {
						ll x1, y;
						if (x < maxi.first) {
							y = bbR(x, maxi.first - 1, na) - 1;
							x1 = x;
						}
						else {
							x1 = bbL(maxi.second + 1, x, na);
							y = x;
						}
						update(1, 0, n - 1, x1, y, na);
					}
				}
				a[x] += v;
				suma += v;
			}
			else {
				cout << query(1, 0, n - 1, 0, n - 1) - suma << endl;
			}
		}
	}
	return 0;
}

