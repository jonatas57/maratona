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

#define lf(x) x << 1
#define rg(x) x << 1 | 1

vector<string> st;

string lcp(string s, string t) {
	if (s == "") return t;
	if (t == "") return s;
	int i;
	for (i = 0;s[i] and t[i] and s[i] == t[i];i++);
	return s.substr(0, i);
}
void build(vector<string>& s, int id, int l, int r) {
	if (l == r) {
		st[id] = s[l];
	}
	else {
		int mid = avg(l, r);
		build(s, lf(id), l, mid);
		build(s, rg(id), mid + 1, r);
		st[id] = lcp(st[lf(id)], st[rg(id)]);
	}
}
void update(int id, int l, int r, int x, string s) {
	if (x > r or x < l) return;
	if (l == r) st[id] = s;
	else if (l <= x and x <= r) {
		int mid = avg(l, r);
		update(lf(id), l, mid, x, s);
		update(rg(id), mid + 1, r, x, s);
		st[id] = lcp(st[id], s);
	}
}

string query(int id, int l, int r, int a, int b) {/*@*/cerr << l << " " << r << "  " << a << " " << b << endl;/*@*/
	if (l > b or a > r) return "";
	if (l <= a and b <= r) return st[id];
	int mid = avg(l, r);
	return lcp(query(lf(id), l, mid, a, b), query(rg(id), mid + 1, r, a, b));
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, q;
	cin >> n >> q;
	vector<string> s(n);
	loop(n) cin >> s[i];
	st.resize(4 * n + 10);
	build(s, 1, 0, n - 1);
	ll op, a, b;
	string x;
	loop(q) {
		cin >> op >> a;
		if (op == 1) {
			cin >> b;
			cout << (b - a + 1) * query(1, 0, n - 1, a - 1, b - 1).length() << endl;
		}
		else {
			cin >> x;
			update(1, 0, n - 1, a, x);
		}
	}
	return 0;
}
