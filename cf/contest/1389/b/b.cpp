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
		int n, k, z;
		cin >> n >> k >> z;
		vi a(n), acc(n + 1, 0), aux(n, 0);
		loop(n) cin >> a[i], acc[i + 1] = acc[i] + a[i];
		loop(n - 1) {
			aux[i] = max(i ? aux[i - 1] : 0, a[i] + a[i + 1]);
		}
		int ans = 0;
		for (int i = k, j = 0;i >= 0;i -= 2, j++) {
			ans = max(ans, acc[i + 1] + min(j, z) * aux[i]);
		}
		cout << ans << endl;
	}
	return 0;
}

