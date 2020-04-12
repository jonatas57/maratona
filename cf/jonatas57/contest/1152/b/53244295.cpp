#include <bits/stdc++.h>

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

int find(int x, int n) {
	while (n >= 0 && x & (1 << n)) n--;
	return n;
}
int power(int a, int b) {
	if (b == 1) return a;
	int x = power(a, b / 2);
	x *= x;
	if (b & 1) x *= a;
	return x;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int x;
	cin >> x;
	int n = log2((double)x);
	int aux = power(2, n + 1) - 1;
	bool p = false;
	vi ans;
	int cnt = 0;
	while (x != aux) {
		if (p) {
			x++;
		}
		else {
			n = find(x, n);
			x ^= power(2, n + 1) - 1;
			ans.push_back(n + 1);
		}
		cnt++;
		p = !p;
	}
	cout << cnt << endl;
	each(x, ans) cout << x << " ";
	cout << endl;
	return 0;
}
