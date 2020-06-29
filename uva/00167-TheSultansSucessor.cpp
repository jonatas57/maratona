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

vector<vector<ii>> solutions;
vector<ii> sol;

bool check(ii a, ii b) {
	int x = abs(a.first - b.first), y = abs(a.second - b.second);
	return x and y and x != y;
}

void eightqueens(int l) {
	if (l == 8) solutions.push_back(sol);
	for (int i = 0;i < 8;i++) {
		bool p = true;
		each(q, sol) {
			p &= check(q, {l, i});
		}
		if (p) {
			sol.emplace_back(l, i);
			eightqueens(l + 1);
			sol.pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	eightqueens(0);
	int k;
	cin >> k;
	loop(k) {
		int ans = 0;
		vector<vi> a(8, vi(8));
		loop(8) vloop(j, 8) cin >> a[i][j];
		each(v, solutions) {
			int sum = 0;
			each(x, v) {
				sum += a[x.first][x.second];
			}
			ans = max(ans, sum);
		}
		cout << setw(5) << ans << endl;
	}
	return 0;
}

