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

	int q;
	cin >> q;
	loop(q) {
		int n, x;
		mii cnt;
		cin >> n;
		loop(4 * n) {
			cin >> x;
			cnt[x]++;
		}
		vector<ii> sticks(cnt.begin(), cnt.end());
		int s = sticks.size();
		bool pos = true;
		int area = sticks[0].first * sticks[s - 1].first;
		for (int i = 0, j = s - 1;i <= j;i++, j--) {
			if (i == j && ((sticks[i].second & 3) || pow(sticks[i].first, 2) != area)) pos = false;
			if (sticks[i].second & 1 || sticks[j].second & 1) pos = false;
			if (sticks[i].second != sticks[j].second) pos = false;
			if (sticks[i].first * sticks[j].first != area) pos = false;
		}
		cout << (pos ? "YES" : "NO") << endl;
	}
	return 0;
}
