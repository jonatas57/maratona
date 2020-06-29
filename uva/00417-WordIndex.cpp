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

int choose(int n, int k) {
	if (k > n) return 0;
	int a = 1;
	loop(k) {
		a *= n - i;
		a /= i + 1;
	}
	return a;
}

int F(int ab, int c, int x) {
	return choose(ab, x) - choose(ab - c, x);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	string s;
	while (cin >> s) {
		string t = s;
		sort(iter(t));
		if (t != s) {
			cout << 0 << endl;
			continue;
		}
		int l = s.length();
		int ans = 1;
		for (int i = 1;i < l;i++) {
			ans += choose(26, i);
		}
		int ab = 0;
		loop(l) {
			int c = s[i] - 'a';
			ans += F(26 - ab, c - ab, l - i);
			ab = c + 1;
		}
		cout << ans << endl;
	}
	return 0;
}

