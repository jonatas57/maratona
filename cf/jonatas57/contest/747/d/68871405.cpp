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

	int n, k;
	cin >> n >> k;
	vb neg(n + 1, false);
	int x, last = 0, qtd = 0, cnt = 0;
	bool ok = false;
	vector<ii> segs;
	for (int i = 1;i <= n;i++) {
		cin >> x;
		if (x < 0) {
			neg[i] = true;
			cnt++;
			if (ok and !neg[i - 1]) {
				segs.emplace_back(i - last - 1, last + 1);
			}
			last = i;
			ok = true;
		}
		else qtd++;
	}
	if (!cnt) cout << 0 << endl;
	else if (cnt <= k) {
		sort(iter(segs));
		segs.emplace_back(n - last, last + 1);
		for (auto& [x, p] : segs) {
			if (cnt + x <= k) {
				loop(x) neg[p + i] = true;
				cnt += x;
			}
		}
		int ans = 0;
		for (int i = 1;i <= n;i++) {
			if (neg[i] != neg[i - 1]) ans++;
		}
		cout << ans << endl;
	}
	else cout << -1 << endl;
	return 0;
}

