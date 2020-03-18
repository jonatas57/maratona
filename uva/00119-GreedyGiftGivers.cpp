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

	int n;
	for (int i = 0;cin >> n;i++) {
		map<string, int> ans;
		string s;
		vector<string> names(n);
		loop(n) cin >> names[i];
		loop(n) {
			int m, k;
			string t;
			cin >> s >> m >> k;
			if (!k) continue;
			int v = m / k;
			ans[s] -= k * v;
			loop(k) {
				cin >> t;
				ans[t] += v;
			}
		}
		if (i) cout << endl;
		each(x, names) {
			cout << x << " " << ans[x] << endl;
		}
	}
	return 0;
}

