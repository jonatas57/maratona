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

vi vs = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
vector<vector<ll>> memo(11, vector<ll>(30001, -1));

ll solve(int val, int c) {
	if (memo[c][val] == -1) {
		if (val == 0 or c == 0) memo[c][val] = 1;
		else {
			memo[c][val] = 0;
			for (int x = val;x >= 0;x -= vs[c]) {
				memo[c][val] += solve(x, c - 1);
			}
		}
	}
	return memo[c][val];
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int a, b;
	char c;
	while (cin >> a >> c >> b and a | b) {
		cout << fixed << setprecision(2) << setw(6) << (double)a + b / 100.0;
		b += a * 100;
		cout << setw(17) << solve(b, 10) << endl;
	}
	return 0;
}

