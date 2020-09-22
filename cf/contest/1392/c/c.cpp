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
		int mx = 0;
		loop(n) {
			cin >> a[i];
			mx = max(a[i], mx);
		}
		a.push_back(mx);
		ll ans = 0;
		int m = a[0], qtd = 0, p = -1;
		vi del;
		for (int i = 1;i <= n;i++) {
			if (a[i] < m) {
				if (p == -1) p = i;
				del.push_back(m - a[i]);
				qtd++;
			}
			else {
				m = a[i];
				if (!del.empty()) {
					ans += del[0];
					for (int j = 1;j < qtd;j++) {
						if (del[j] > del[j - 1]) {
							ans += del[j] - del[j - 1];
						}
					}
					del.clear();
					qtd = 0;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}

