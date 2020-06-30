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
		cin >> n >> k;
		vi a(n);
		loop(n) cin >> a[i];
		vi ps;
		int m = 0;
		for (int i = 1;i < n - 1;i++) {
			if (a[i - 1] < a[i] and a[i] > a[i + 1]) ps.push_back(i), m++;
		}
		int ans = 0, qtd = 0, l = 1;
		for (int i = 0, j = 0, nx = 0;j < m;i++) {
			if (i == ps[nx]) qtd--, nx++;
			while (j < m and ps[j] < i + k - 1) qtd++, j++;
			if (ans < qtd) {
				ans = qtd;
				l = i + 1;
			}
		}
		cout << ans + 1 << " " << l << endl;
	}
	return 0;
}

