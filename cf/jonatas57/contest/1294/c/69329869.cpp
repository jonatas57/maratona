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

vi fat(int n) {
	vi fs;
	for (int i = 2;i * i <= n;i++) {
		while (n % i == 0) {
			fs.push_back(i);
			n /= i;
		}
	}
	if (n > 1) fs.push_back(n);
	return fs;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int t;
	cin >> t;
	loop(t) {
		int n;
		cin >> n;
		vi fs = fat(n);
		vi ans;
		int l = fs.size(), x = 1;
		bool p = true;
		if (l >= 3) {
			ans.push_back(fs[0]);
			ans.push_back(fs[1]);
			x *= fs[0] * fs[1];
			if (fs[0] == fs[1]) {
				x *= fs[2];
				ans[1] *= fs[2];
			}
			int y = n / x;
			if (y >= 2 and ans[0] != y and ans[1] != y) {
				ans.push_back(y);
			}
			else p = false;
		}
		else p = false;
		if (p) {
			cout << "YES" << endl;
			each(x, ans) cout << x << " ";
			cout << endl;
		}
		else cout << "NO" << endl;
	}
	return 0;
}

