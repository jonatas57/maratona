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

#define left(x) x << 1
#define right(x) x << 1 | 1

vector<ll> st2, lazy;
vector<pair<ll, ii>> st;

auto max(pair<ll, ii> a, pair<ll, ii> b) {
	if (a.first == b.first) {
		a.second = {min(a.second.first, b.second.first), max(a.second.second, b.second.second)};
		return a;
	}
	else return a < b ? b : a;
}

void build(vector<ll>& b, int id, int l, int r) {
	if (l == r) {
		st[id] = make_pair(b[l], ii(l, l));
		st2[id] = b[l];
		lazy[id] = 0;
	}
	else {
		int mid = avg(l, r);
		build(b, left(id), l, mid);
		build(b, right(id), mid + 1, r);
		st[id] = max(st[left(id)], st[right(id)]);
		st2[id] = st2[left(id)] + st2[right(id)];
		lazy[id] = 0;
	}
}
void prop(int id, int l, int r) {
	if (lazy[id]) {
		if (lazy[id] > st[id].first) st[id] = {lazy[id], ii(l, r)};
		st2[id] = lazy[id] * (r - l + 1);
		if (l != r) {
			lazy[left(id)] = lazy[right(id)] = lazy[id];
		}
		lazy[id] = 0;
	}
}

void update(int id, int l, int r, int a, int b, ll val) {
	prop(id, l, r);
	if (l > b or r < a) return;
	if (l >= a and r <= b) lazy[id] = val, prop(id, l, r);
	else {
		int mid = avg(l, r);
		update(left(id), l, mid, a, b, val);
		update(right(id), mid + 1, r, a, b, val);
		st[id] = max(st[left(id)], st[right(id)]);
		st2[id]= st2[left(id)] + st2[right(id)];
	}
}

auto query(int id, int l, int r, int a, int b) {
	prop(id, l, r);
	if (l > b or r < a) return make_pair(0ll, ii(-1, -1));
	if (l >= a and r <= b) return st[id];
	int mid = avg(l, r);
	return max(query(left(id), l, mid, a, b), query(right(id), mid + 1, r, a, b));
}

ll squery(int id, int l, int r, int a, int b) {
	prop(id, l, r);
	if (l > b or r < a) return 0;
	if (l >= a and r <= b) return st2[id];
	int mid = avg(l, r);
	return squery(left(id), l, mid, a, b) + squery(right(id), mid + 1, r, a, b);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n, q;
		cin >> n >> q;
		st.resize(4 * n + 10);
		st2.resize(4 * n + 10);
		lazy.resize(4 * n + 10);
		vector<ll> a(n), b(n);
		ll suma = 0, m = 0, pos;
		loop(n) {
			cin >> a[i];
			suma += a[i];
			b[i] = a[i];
			if (m < a[i]) {
				m = a[i];
				pos = i;
			}
		}
		for (int i = 1;i < pos;i++) {
			b[i] = max(b[i], b[i - 1]);
		}
		for (int i = n - 2;i > pos;i--) {
			b[i] = max(b[i], b[i + 1]);
		}
		build(b, 1, 0, n - 1);
		char op;
		int x, v;
		loop(q) {
			cin >> op;
			if (op == 'U') {
				cin >> x >> v;
				x--;
				ll na = a[x] + v;
				if (na > b[x]) {
					auto tall = query(1, 0, n - 1, 0, n - 1);
					ll nb = min(na, tall.first);
					if (x < tall.second.first) {
						int p = upper_bound(b.begin() + x + 1, b.begin() + tall.second.first, na) - b.begin();
						update(1, 0, n - 1, x + 1, p - 1, nb);
					}
					else if (x > tall.second.second) {
						int p = n - 1 - (upper_bound(b.rbegin() + n - 1 - tall.second.first, b.rbegin() + n - x, na) - b.rbegin());
						update(1, 0, n - 1, p + 1, x - 1, nb);
					}
					update(1, 0, n - 1, x, x, na);
				}
				a[x] = na;
				suma += v;
			}
			else { 
				cout << squery(1, 0, n - 1, 0, n - 1) - suma << endl;
			}
		}
	}
	return 0;
}

