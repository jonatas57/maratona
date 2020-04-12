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

	int n, a, b;
	cin >> n >> a >> b;
	vi ans(1, 1);
	int x = 1;
	if (a and !b) {
		ans.push_back(1);
		x++;
	}
	bool p = false;
	for (int i = 0;i < n - x and !p;i++) {
		if (b) {
			b--;
			ans.push_back(ans.back() << 1);
		}
		else if (a) {
			a--;
			ans.push_back(ans.back() + 1);
		}
		else ans.push_back(1);
		if (ans.back() > 50000) {
			p = true;
		}
	}
	if (a or b or p) cout << -1 << endl;
	else {
		each(x, ans) cout << x << " ";
		cout << endl;
	}
	return 0;
}

