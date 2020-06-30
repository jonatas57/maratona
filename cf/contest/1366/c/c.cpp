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
		int n, m;
		cin >> n >> m;
		int x = (n + m - 1) / 2, sz = x + (n + m) % 2;
		vector<mii> cnt(sz + 1);
		loop(n) vloop(j, m) {
			int y = i + j, z;
			cin >> z;
			if (y < x) cnt[y][z]++;
			else cnt[n + m - y - 2][z]++;
		}
		int ans = 0;
		loop(sz) {
			int sum = 0, mx = 0;
			for (auto& [k, v] : cnt[i]) {
				sum += v;
				mx = max(mx, v);
			}
			ans += sum - mx;
		}
		cout << ans << endl;
	}
	return 0;
}

