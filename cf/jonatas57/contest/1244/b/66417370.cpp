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
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

int n;
string sc;

vector<vb> visit;

int dfs(int l, int c) {
	if (l < 0 or l > 1 or c < 0 or c >= n or visit[l][c]) return 0;
	visit[l][c] = true;
	int ans = 0;
	loop(2) {
		ans = max(ans, dfs(l, c + (i & 1 ? -1 : 1)));
	}
	if (sc[c] == '1') ans = max(ans, dfs(l ^ 1, c));
	return ans + 1;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		cin >> n >> sc;
		int ans = 0;
		loop(4) {
			visit.assign(2, vb(n, false));
			ans = max(ans, dfs(i & 1, i & 2 ? n - 1 : 0));
		}
		cout << ans << endl;
	}
	return 0;
}

