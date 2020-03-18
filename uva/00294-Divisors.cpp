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

int qtddiv(int x) {
	int ans = 1;
	for (int i = 2;i * i <= x;i++) {
		int qtd = 0;
		while (x % i == 0) {
			qtd++;
			x /= i;
		}
		if (qtd) ans *= qtd + 1;
	}
	if (x > 1) ans *= 2;
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, l, h;
	cin >> n;
	loop(n) {
		cin >> l >> h;
		int ans, qtd = 0;
		for (int i = l;i <= h;i++) {
			int x = qtddiv(i);
			if (qtd < x) ans = i, qtd = x;
		}
		cout << "Between " << l << " and " << h << ", " << ans << " has a maximum of " << qtd << " divisors." << endl;
	}
	return 0;
}

