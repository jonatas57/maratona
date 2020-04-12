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
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	mii cnt;
	int m, ans = -1;
	vi a(n);
	loop(n) {
		cin >> a[i];
		cnt[a[i]]++;
		if (ans == -1 and cnt[a[i]] == n) ans = 0;
	}
	cin >> m;
	loop(m) {
		int k, x;
		cin >> k >> x;
		cnt[a[k - 1]]--;
		a[k - 1] = x;
		cnt[x]++;
		if (ans == -1 and cnt[x] == n) ans = i + 1;
	}
	cout << ans << endl;
	return 0;
}

