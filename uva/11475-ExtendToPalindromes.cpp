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

const char first = '#';
const char last = 'z';
const int asz = last - first + 1;

pair<vi, vi> suffixArray(string& s) {
	s += '$';
	int n = s.length();

	vi p(n), c(n, 0), cnt(asz, 0);
	loop(n) cnt[s[i] - first]++;
	loop(asz - 1) cnt[i + 1] += cnt[i];
	loop(n) p[--cnt[s[i] - first]] = i;

	int nc = 1;
	for (int i = 1;i < n;i++) {
		if (s[p[i]] != s[p[i - 1]]) nc++;
		c[p[i]] = nc - 1;
	}

	vi p2(n), c2(n, 0);
	for (int h = 1;h < n;h <<= 1) {
		loop(n) {
			p2[i] = p[i] - h;
			if (p2[i] < 0) p2[i] += n;
		}

		cnt.assign(n, 0);
		loop(n) cnt[c[p2[i]]]++;
		for (int i = 1;i < nc;i++) cnt[i] += cnt[i - 1];
		for (int i = n - 1;i >= 0;i--) p[--cnt[c[p2[i]]]] = p2[i];

		ii prev(0, c[h]), cur;
		nc = 1;
		for (int i = 1;i < n;i++) {
			cur = make_pair(c[p[i]], c[(p[i] + h) % n]);
			if (cur != prev) nc++;
			c2[p[i]] = nc - 1;
			prev = cur;
		}
		c.swap(c2);
	}
	return make_pair(p, c);
}

const int N = 200010;
const int T = 4 * N + 10;
vi st(T);
void build(vi& a, int id, int l, int r) {
	if (l == r) st[id] = a[l];
	else {
		int mid = avg(l, r);
		build(a, id << 1, l, mid);
		build(a, id << 1 | 1, mid + 1, r);
		st[id] = min(st[id << 1], st[id << 1 | 1]);
	}
}
int query(int id, int l, int r, int a, int b) {
	if (r < a or l > b) return INF;
	if (a <= l and r <= b) return st[id];
	int mid = avg(l, r);
	return min(query(id << 1, l, mid, a, b), query(id << 1 | 1, mid + 1, r, a, b));
}

int n;
vi lcp, p, c;
int getlcp(int i, int j) {
	if (i == j) return n - i + 1;
	i = c[i], j = c[j];
	if (i > j) swap(i, j);
	return query(1, 0, n - 1, i, j - 1);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	string s, t;
	while (cin >> t) {
		s = t + "#" + string(riter(t));
		n = s.length();
		int ls = t.length();
		tie(p, c) = suffixArray(s);
		lcp.resize(n);
		int k = 0;
		loop(n) {
			if (!isalpha(s[i])) continue;
			int j = p[c[i] - 1];
			while (s[i + k] == s[j + k]) k++;
			lcp[c[i] - 1] = k;
			k = max(k - 1, 0);
		}
		build(lcp, 1, 0, n - 1);
		int pos = -1;
		loop(ls) {
			int x = getlcp(i, ls + 1);
			if (i + x == ls) {
				pos = i;
				break;
			}
		}
		for (int i = pos - 1;i >= 0;i--) t += t[i];
		cout << t << endl;
	}
	return 0;
}


