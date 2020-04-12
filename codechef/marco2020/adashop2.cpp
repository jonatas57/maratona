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

void walk(int& r, int& c, vector<ii>& ans) {
	int x = r + c;
	int i = 1, j = x - 1;
	if (j > 8) i += j - 8, j = 8;
	if (r > i) ans.emplace_back(i, j);
	if (c > i) ans.emplace_back(j, i);
	if (r != 1 and r != 8) ans.emplace_back(x >> 1, x >> 1);
	r = c = x >> 1;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		int r, c;
		cin >> r >> c;
		vb visit(8, false);
		vector<ii> ans(1, {r, c});
		walk(r, c, ans);
		visit[((r + c) >> 1) - 1] = true;
		for (int i = 0;i < 8;i++) {
			if (visit[i]) continue;
			r = c = i + 1;
			ans.emplace_back(r, c);
			visit[i] = true;
			walk(r, c, ans);
		}
		cout << ans.size() << endl;
		each(p, ans) cout << p.first << " " << p.second << endl;
	}
	return 0;
}

