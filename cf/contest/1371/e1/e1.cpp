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

	int n, p;
	cin >> n >> p;
	vi a(n);
	loop(n) cin >> a[i];
	sort(iter(a));
	vi ans;
	loop(2000) {
		bool good = true;
		int cnt = 0;
		vloop(j, n) {
			while (cnt < n and a[cnt] <= i + j) cnt++;
			if (cnt - j == p) good = false;
			else if (cnt - j == 0) {
				good = false;
				break;
			}
		}
		if (good) ans.push_back(i);
	}
	cout << ans.size() << endl;
	each(x, ans) cout << x << " ";
	cout << endl;
	return 0;
}

