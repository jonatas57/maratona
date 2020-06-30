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
		int n, x, m;
		cin >> n >> x >> m;
		int l = x, r = x;
		vector<ii> a(m);
		loop(m) {
			cin >> a[i].first >> a[i].second;
		}
		loop(m) {
			if (a[i].second < l or a[i].first > r) continue;
			l = min(l, a[i].first);
			r = max(r, a[i].second);
		}
		cout << r - l + 1 << endl;
	}
	return 0;
}

