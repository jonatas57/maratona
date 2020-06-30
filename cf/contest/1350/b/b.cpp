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
		vi s(n);
		loop(n) cin >> s[i];
		vi ans(n, 1);
		for (int i = 2;i <= n;i++) {
			for (int j = 1;j * j <= i;j++) {
				if (i % j == 0) {
					int a = j - 1;
					int b = i / j - 1;
					if (s[a] < s[i - 1]) ans[i - 1] = max(ans[i - 1], ans[a] + 1);
					if (s[b] < s[i - 1]) ans[i - 1] = max(ans[i - 1], ans[b] + 1);
				}
			}
		}
		int x = 1;
		loop(n) x = max(x, ans[i]);
		cout << x << endl;
	}
	return 0;
}

