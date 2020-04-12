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

	int n, k;
	cin >> n >> k;
	int c = 1;
	bool p = false;
	vector<ii> ans;
	loop(n) {
		if (k == c) {
			c = 1;
			k--;
			p = !p;
			if (k == 1) {
				ans.clear();
				break;
			}
		}
		if ((i & 1) ^ p) ans.emplace_back(k, c);
		else ans.emplace_back(c, k);
		if (i & 1) c++;
	}
	if (ans.size()) {
		cout << "YES" << endl;
		for (auto& [b, g] : ans) cout << b << " " << g << endl;
	}
	else cout << "NO" << endl;
	return 0;
}

