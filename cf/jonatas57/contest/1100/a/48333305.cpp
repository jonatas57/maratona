#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define each(x, s)         for(auto& x : s)
#define ceach(x, s)        for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define pb                 push_back

int main() {
	ios_base::sync_with_stdio(false);

	int n, k;
	cin >> n >> k;
	vi tab(n);
	int sum = 0;
	loop(n) {
		cin >> tab[i];
		sum += tab[i];
	}
	int rem = 0;
	loop(k) {
		int aux = 0;
		for (int j = i;j < n;j += k) {
			aux += tab[j];
		}
		int x = abs(sum - aux);
		rem = max(rem, x);
	}
	cout << rem << endl;
	return 0;
}
