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
	vi m(k), c(k + 1, 0);
	int x;
	loop(n) cin >> x, m[x - 1]++;
	loop(k) cin >> c[i];
	vector<vi> ans(n);
	vi szs(n, 0);
	int sz = 0;
	int j = 0;
	for (int i = k - 1;i >= 0;i--) {
		if (c[i] > c[i + 1]) j = 0;
		for (;m[i];) {
			if (j == sz) {
				sz++;
			}
			if (szs[j] == c[i]) {
				j++;
				continue;
			}
			int q = min(m[i], c[i] - szs[j]);
			vloop(aux, q) ans[j].push_back(i + 1), szs[j]++;
			m[i] -= q;
			if (m[i]) j++;
		}
	}
	cout << sz << endl;
	loop(sz) {
		cout << szs[i];
		vloop(j, szs[i]) cout << " " << ans[i][j];
		cout << endl;
	}
	return 0;
}

