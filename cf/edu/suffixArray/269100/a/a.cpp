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
	s += '$';
	int n = s.length();
	vi p(n), c(n, 0);
	loop(n) p[i] = i;
	sort(iter(p), [s](int a, int b) {
		return s[a] == s[b] ? a < b : s[a] < s[b];
	});
	for (int i = 1;i < n;i++) {
		c[i] = c[i - 1];
		if (s[p[i]] != s[p[i - 1]]) c[i]++;
	}
	for (int h = 1;h < n;h <<= 1) {
		vi pos(n);
		loop(n) pos[p[i]] = i;
		vector<tuple<int, int, int>> aux;
		loop(n) aux.emplace_back(c[i], c[pos[(p[i] + h) % n]], p[i]);
		sort(iter(aux));
		loop(n) {
			auto& [c1, c2, pi] = aux[i];
			p[i] = pi;
			if (i) {
				c[i] = c[i - 1];
				if (c1 != get<0>(aux[i - 1]) or c2 != get<1>(aux[i - 1])) c[i]++;
			}
		}
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

