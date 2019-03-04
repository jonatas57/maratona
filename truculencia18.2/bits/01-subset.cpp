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

vi sums(vi& v, int l, int r) {
	int x = r - l + 1, n = 1 << x, sum;
	vi sums;
	vloop(mask, n) {
		sum = 0;
		for (int i = 0;i < x;i++) {
			if (mask & (1 << i)) {
				sum += v[l + i];
			}
		}
		sums.push_back(sum);
	}
	return sums;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, a, b;
	cin >> n >> a >> b;
	vi s(n);
	loop(n) {
		cin >> s[i];
	}
	int mid = (n - 1) / 2;
	vi s1 = sums(s, 0, mid), s2 = sums(s, mid + 1, n - 1);
	sort(s1.begin(), s1.end());
	ull qtd = 0;
	each(x, s2) {
		int p = a - x, q = b - x;
		auto low = lower_bound(s1.begin(), s1.end(), p), 
				 hig = upper_bound(s1.begin(), s1.end(), q);
		qtd += hig - low;
	}
	cout << qtd << endl;
	return 0;
}
