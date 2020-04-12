#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define MAX                100000
#define N                  4 * MAX + 10
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define ceach(x, s)        for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;
	vector<vi> a(n, vi(m, 0));
	loop(n) vloop(j, m) cin >> a[i][j];
	int scr = 0, mini = 0;
	loop(m) {
		int next = 0, ans = 0, cnt = 0, aux = 0;
		vloop(j, n) {
			while(j < n && !a[j][i]) j++;
			int x = min(k, n - j), sum = 0;
			bool p = true;
			for (int z = 0;z < x;z++) {
				sum += a[j + z][i];
				if (p && z && a[j + z][i]) next = j + z, p = false;
			}
			if (sum > ans) {
				ans = sum;
				cnt = aux;
			}
			aux++;
			if (next > j) j = next - 1;
		}
		scr += ans;
		mini += cnt;
	}
	cout << scr << " " << mini << endl;
	return 0;
}
