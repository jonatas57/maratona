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

	int n;
	cin >> n;
	vi a(n);
	vi z;
	int qtd = 0;
	loop(n) {
		cin >> a[i];
		if (!a[i]) z.push_back(i), qtd++;
	}
	int k = 0, j = n - 1;
	for (;k < z[0] && k < n;k++) a[k] = z[0] - k;
	for (;j > z[qtd - 1];j--) a[j] = j - z[qtd - 1];
	int x = 0;
	rep(k, j, 1) {
		a[i] = min(abs(z[x] - i), abs(z[x - 1] - i));
		if (i == z[x]) x++;
	}
	each(x, a) cout << x << " ";cout << endl;
	return 0;
}
