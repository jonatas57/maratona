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

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	vector<ii> a;
	int x, y, u, v;
	cin >> x >> y;
	loop(n - 1) {
		cin >> u >> v;
		a.emplace_back(u - x, v - y);
	}
	int cnt = 0;
	for (int i = 1;i < n - 1;i++) {
		if (a[i - 1].first * a[i].second - a[i - 1].second * a[i].first < 0) cnt++; 
	}
	cout << cnt << endl;
	return 0;
}
