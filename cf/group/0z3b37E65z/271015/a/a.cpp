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

	int m, k, n, s;
	cin >> m >> k >> n >> s;
	int maxr = m - k * n;
	vi lia(m);
	loop(m) cin >> lia[i];
	vi b(5e5 + 1, 0);
	int x;
	loop(s) {
		cin >> x;
		b[x]++;
	}
	bool p = false, rem = false;
	vi cnt(5e5 + 1, 0), ans;
	int up = k + maxr, ok = 0;
	for (int i = 0, j = 0;j < m or rem;) {
		if (j - i < up and !rem) {
			cnt[lia[j]]++;
			if (cnt[lia[j]] <= b[lia[j]]) ok++;
			j++;
		}
		else {
			if (cnt[lia[i]] <= b[lia[i]]) ok--;
			cnt[lia[i]]--;
			i++;
			rem = false;
		}
		if (ok == s) {
			int tor = j - i + (i % k) - k;
			if (tor <= maxr) {
				p = true;
				int x = i - i % k;
				for (int y = x, r = 0;y < j and r < tor;y++) {
					if (!b[lia[y]]) {
						ans.push_back(y + 1);
						r++;
					}
				}
				break;
			}
			else {
				rem = true;
			}
		}
	}
	if (p) {
		cout << ans.size() << endl;
		each(x, ans) cout << x << " ";
		cout << endl;
	}
	else cout << -1 << endl;
	return 0;
}

