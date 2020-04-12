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

	int t;
	cin >> t;
	loop(t) {
		string s, t;
		cin >> s >> t;
		map<char, vi> pos;
		for (int i = 0;s[i];i++) {
			pos[s[i]].push_back(i);
		}
		bool imp = false;
		each(x, t) {
			if (!pos[x].size()) {
				imp = true;
			}
		}
		if (imp) cout << -1 << endl;
		else {
			int last = -1, ans = 1;
			for (int i = 0;t[i];i++) {
				char c = t[i];
				auto it = lower_bound(iter(pos[c]), last + 1);
				if (it == pos[c].end()) {
					ans++;
					last = *pos[c].begin();
				}
				else last = *it;
			}
			cout << ans << endl;
		}
	}
	return 0;
}

