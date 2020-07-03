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

const char first = '$';
const char last = 'z';
const int asz = last - first + 1;

vi suffixArray(string& s) {
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

		fill(cnt.begin(), cnt.begin() + nc, 0);
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
	return p;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	string s;
	cin >> s;
	each(x, suffixArray(s)) cout << x << " ";
	cout << endl;
	return 0;
}

