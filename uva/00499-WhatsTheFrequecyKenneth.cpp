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

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	string s;
	while (getline(cin, s)) {
		map<char, int> cnt;
		each(c, s) if (isalpha(c)) cnt[c]++;
		vector<pair<char, int>> ans(iter(cnt));
		sort(iter(ans), [](ii a, ii b) {
			return a.second == b.second ? a.first < b.first : a.second > b.second;
		});
		int x = ans[0].second, l = ans.size();
		for (int i = 0;i < l and ans[i].second == x;i++) {
			cout << ans[i].first;
		}
		cout << " " << x << endl;
	}
	return 0;
}

