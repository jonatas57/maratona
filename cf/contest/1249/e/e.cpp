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

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, c;
	cin >> n >> c;
	vi a(n), b(n);
	vector<pair<int, bool>> ans(n);
	a[0] = b[0] = 0;
	ans[0] = {0, false};
	loop(n - 1) cin >> a[i + 1];
	loop(n - 1) cin >> b[i + 1];
	int last;
	bool el;
	for (int i = 1;i < n;i++) {
		tie(last, el) = ans[i - 1];
		int esc = last + a[i];
		int ele = last + b[i] + (el ? 0 : c);
		if (ele <= esc) {
			ans[i] = {ele, true};
		}
		else ans[i] = {esc, false};
	}
	for (auto& [last, el] : ans) {
		cout << last << " ";
	}
	cout << endl;
	return 0;
}

