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

	vi b(4);
	int sum = 0;
	loop(4) cin >> b[i], sum += b[i];
	if (sum & 1) {
		cout << "NO" << endl;
		return 0;
	}
	sum /= 2;
	loop(4) {
		if (sum == b[i]) {
			cout << "YES" << endl;
			return 0;
		}
	}
	loop(4) {
		for (int j = i + 1;j < 4;j++) {
			if (b[i] + b[j] == sum) {
				cout << "YES" << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}

