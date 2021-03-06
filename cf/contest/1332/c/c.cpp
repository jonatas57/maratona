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
		int n, k;
		string s;
		cin >> n >> k >> s;
		int ans = 0, l = n / k;
		for (int i = 0;i <= k - i - 1;i++) {
			vi cnt(26, 0);
			int x = i, y = k - i - 1, m = 0;
			for (int j = 0;y < n;j++) {
				if (x != y) m = max({m, ++cnt[s[x] - 'a'], ++cnt[s[y] - 'a']});
				else m = max(m, ++cnt[s[x] - 'a']);
				x += k;
				y += k;
			}
			ans += (x == y ? l : 2 * l) - m;
		}
		cout << ans << endl;
	}
	return 0;
}

