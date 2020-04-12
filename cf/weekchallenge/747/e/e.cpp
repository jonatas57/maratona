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
	cin >> s;
	vector<pair<string, int>> com;
	int x = 0;
	bool p = false;
	string c = "";
	loop(s.length() + 1) {
		if (ispunct(s[i]) or !s[i]) {
			if (p) {
				com.emplace_back(c, x);
				c = "";
				x = 0;
			}
			p = !p;
		}
		else {
			if (p) {
				x *= 10;
				x += s[i] - '0';
			}
			else {
				c += s[i];
			}
		}
	}
	vector<vector<string>> ans;
	int dep = 0, anssz = 0;
	stack<int> qtds;
	for (auto& [c, x] : com) {
		while (dep and !qtds.top()) dep--, qtds.pop();
		if (anssz <= dep) ans.emplace_back(), anssz++;
		ans[dep].push_back(c);
		if (dep) {
			qtds.top()--;
		}
		if (x) {
			dep++;
			qtds.push(x);
		}
	}
	cout << ans.size() << endl;
	each(v, ans) {
		each(s, v) {
			cout << s << " ";
		}
		cout << endl;
	}
	return 0;
}

