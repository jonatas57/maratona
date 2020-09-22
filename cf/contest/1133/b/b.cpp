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

	int n, k;
	cin >> n >> k;
	vi d(n);
	mii count;
	loop(n) {
		cin >> d[i];
		count[d[i] % k]++;
	}
	int total = count[0] - (count[0] & 1);
	for (int i = 1;i < (k + 1) / 2;i++) {
		total += 2 * min(count[i], count[k - i]);
	}
	if ((k - 1) & 1) {
		total += count[k / 2] - (count[k / 2] & 1);
	}
	cout << total << endl; 
	return 0;
}
