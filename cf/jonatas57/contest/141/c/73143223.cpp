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

	int n;
	cin >> n;
	vector<pair<int, string>> a(n), ans;
	loop(n) {
		cin >> a[i].second >> a[i].first;
	}
	sort(iter(a));
	int x = 0;
	for (auto& [h, s] : a) {
		if (h > x) {
			ans.clear();
			break;
		}
		ans.insert(ans.begin() + h, make_pair(3000 - h, s));
		x++;
	}
	if (ans.empty()) cout << -1 << endl;
	else {
		for (auto& [h, s] : ans) cout << s << " " << h << endl;
	}
	return 0;
}

