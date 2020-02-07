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

vi coins = {1, 5, 10, 25, 50};
vector<vi> memo(7490, vi(5, -1));

int calc(int x, int c = 4) {
	if (memo[x][c] == -1) {
		if (c == 0 or x == 0) memo[x][c] = 1;
		else if (coins[c] > x) memo[x][c] = calc(x, c - 1);
		else {
			int ans = 0;
			for (int i = 0;i <= x;i += coins[c]) {
				ans += calc(x - i, c - 1);
			}
			memo[x][c] = ans;
		}
	}
	return memo[x][c];
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int x;
	while (cin >> x) {
		cout << calc(x) << endl;
	}
	return 0;
}

