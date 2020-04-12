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
	cin >> n;
	vi cnt(5, 0);
	int x;
	loop(n) cin >> x, cnt[x]++;
	int ans = cnt[4];
	x = min(cnt[1], cnt[3]);
	ans += x;
	cnt[1] -= x;
	cnt[3] -= x;
	ans += cnt[2] / 2;
	if (cnt[2] & 1) {
		ans++;
		cnt[1] -= min(2, cnt[1]);
	}
	ans += cnt[3];
	ans += (cnt[1] + 3) / 4;
	cout << ans << endl;
	return 0;
}
