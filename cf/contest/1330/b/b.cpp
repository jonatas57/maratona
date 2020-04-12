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

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		int n;
		cin >> n;
		vi a(n);
		int m = 0;
		loop(n) {
			cin >> a[i];
			m = max(m, a[i]);
		}
		set<ii> ans;

		vi aux = {m, n - m};
		loop(2) {
			vi cntl(n + 1, 0), cntr(n + 1, 0);
			vloop(j, n) {
				if (j < aux[i]) cntl[a[j]]++;
				else cntr[a[j]]++;
			}
			int l, r;
			for (l = 1;l <= n and cntl[l] == 1;l++);
			for (r = 1;r <= n and cntr[r] == 1;r++);
			l--, r--;
			if (l and r and l + r == n) ans.emplace(l, r);
		}

		if (ans.empty()) cout << 0 << endl;
		else {
			cout << ans.size() << endl;
			for (auto& [a, b] : ans) {
				cout << a << " " << b << endl;
			}
		}
	}
	return 0;
}

