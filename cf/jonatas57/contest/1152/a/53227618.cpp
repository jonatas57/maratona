#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;

#define INF                0x3f3f3f3f
#define each(x, s)         for(auto& x : s)
#define ceach(x, s)        for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define pb                 push_back
#define avg(x, y)          x + (y - x) / 2
#define left(x)            x << 1
#define right(x)           x << 1 | 1

#define N                  1024000
#define SIZE               4 * N + 10

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	vi kp, ki, cp, ci;
	int x;
	loop(n) {
		cin >> x;
		if (x & 1) ci.push_back(x);
		else cp.push_back(x);
	}
	loop(m) {
		cin >> x;
		if (x & 1) ki.push_back(x);
		else kp.push_back(x);
	}
	int ans = min(ki.size(), cp.size());
	ans += min(kp.size(), ci.size());
	cout << ans << endl;
	return 0;
}
