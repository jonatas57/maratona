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

	int n, m, ta, tb, k;
	cin >> n >> m >> ta >> tb >> k;
	deque<int> a(n), b(m);
	loop(n) cin >> a[i];
	loop(m) cin >> b[i];
	bool p = true;
	int ark = 0;
	if (n <= k || m <= k) p = false;
	else {
		ark = a[0] + ta;
		auto it = lower_bound(b.begin(), b.end(), ark);
		ark = *it + tb;
		int x = 0, y = it - b.begin();
		if (k > m - y) p = false;
		else {
			loop(k) {
				int aux, aux2;
				aux = a[x + 1] + ta;
				int j;
				for (j = y + 1;j < m && b[j] < aux;j++);
				if (j == m) {
					p = false;
					aux = 0;
					break;
				}
				else aux = b[j] + tb;
				if (y + 1 < m) {
					aux2 = b[y + 1] + tb;
				}
				else {
					p = false;
					aux2 = 0;
				}
				if (aux >= aux2) x++, y = j, ark = aux;
				else y++, ark = aux2;
			}
		}
	}
	cout << (p ? ark : -1) << endl;
	return 0;
}

