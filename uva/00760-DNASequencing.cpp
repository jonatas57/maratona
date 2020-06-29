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

vi suffixArray(string& s) {
	int n = s.size();
	const int alphabet = 256;

	vi p(n), c(n), cnt(max(alphabet, n), 0);
	loop(n) cnt[s[i]]++;
	for (int i = 1; i < alphabet; i++) cnt[i] += cnt[i-1];
	loop(n) p[--cnt[s[i]]] = i;
	c[p[0]] = 0;
	int classes = 1;
	for (int i = 1; i < n; i++) {
		if (s[p[i]] != s[p[i-1]]) classes++;
		c[p[i]] = classes - 1;
	}

	vi pn(n), cn(n);
	for (int h = 1;h < n;h <<= 1) {
		for (int i = 0; i < n; i++) {
			pn[i] = p[i] - h;
			if (pn[i] < 0) pn[i] += n;
		}
		fill(cnt.begin(), cnt.begin() + classes, 0);
		loop(n) cnt[c[pn[i]]]++;
		for (int i = 1; i < classes; i++) cnt[i] += cnt[i-1];
		for (int i = n - 1;i >= 0;i--) p[--cnt[c[pn[i]]]] = pn[i];
		cn[p[0]] = 0;
		classes = 1;
		ii cur, prev(0, c[h % n]);
		for (int i = 1; i < n; i++) {
			cur = {c[p[i]], c[(p[i] + h) % n]};
			if (cur != prev) ++classes;
			cn[p[i]] = classes - 1;
			prev = cur;
		}
		c.swap(cn);
	}
	return p;
}

vi getLCP(string& s, vi& p) {
	int n = s.size();
	vi rank(n, 0);
	loop(n) rank[p[i]] = i;

	int k = 0;
	vi lcp(n - 1, 0);
	loop(n) {
		if (rank[i] == n - 1) {
			k = 0;
			continue;
		}
		int j = p[rank[i] + 1];
		while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
		lcp[rank[i]] = k;
		if (k) k--;
	}
	return lcp;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	string a, b;
	for (int i = 0;cin >> a >> b;i++) {
		if (i) cout << endl;
		string s = a + ' ' + b + '$';
		int la = a.length();
		vi sa = suffixArray(s);
		vi lcp = getLCP(s, sa);
		int l = lcp.size();
		int ml = 0;
		vi ans;
		for (int i = 2;i < l;i++) {
			if ((sa[i] < la) ^ (sa[i + 1] < la)) {
				if (ml < lcp[i]) {
					ml = lcp[i];
					ans.clear();
				}
				if (ml == lcp[i]) ans.push_back(sa[i]);
			}
		}
		set<string> lcs;
		if (ml) {
			each(x, ans) {
				string ss = "";
				loop(ml) ss += s[x + i];
				lcs.insert(ss);
			}
			each(s, lcs) cout << s << endl;
		}
		else cout << "No common sequence." << endl;
	}
	return 0;
}

