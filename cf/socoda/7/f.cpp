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

int kmp(vi& t, vi& p) {
	int i = 0, j = -1;
	int n = t.size(), m = p.size(), ans = 0;
	if (!m) return n + 1;
	if (!n) return 0;
	vi b(m + 20, 0);
	b[0] = -1;
	while (i < m) {
		while (j >= 0 && p[i] != p[j]) j = b[j];
		i++, j++;
		b[i] = j;
	}
	i = 0, j = 0;
	while (i < n) {
		while (j >= 0 && t[i] != p[j]) j = b[j];
		i++, j++;
		if (j == m) {
			ans++;
			j = b[j];
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, w;
	cin >> n >> w;
	vi t, p;
	int x, y;
	cin >> x;
	loop(n - 1) {
		cin >> y;
		t.push_back(y - x);
		x = y;
	}
	cin >> x;
	loop(w - 1) {
		cin >> y;
		p.push_back(y - x);
		x = y;
	}
	cout << kmp(t, p) << endl;
	return 0;
}

