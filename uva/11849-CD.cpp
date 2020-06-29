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

	int n, m;
	while (cin >> n >> m and n | m) {
		vector<set<int>> s(2);
		int a = 0, b = 1, x;
		loop(n) cin >> x, s[0].insert(x);
		loop(m) cin >> x, s[1].insert(x);
		if (n > m) swap(a, b);
		int ans = 0;
		each(x, s[a]) ans += s[b].count(x);
		cout << ans << endl;
	}
	return 0;
}

