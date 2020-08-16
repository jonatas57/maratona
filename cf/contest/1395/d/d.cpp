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

	int n, d, m;
	cin >> n >> d >> m;
	vector<ll> a(n), g, l;
	loop(n) {
		cin >> a[i];
		if (a[i] > d) g.push_back(a[i]);
		else l.push_back(a[i]);
	}
	sort(riter(g));
	sort(riter(l));
	int x = (g.size() - 1) / (d + 1) + 1;
	ll sum = 0;
	ll ans = 0;
	int y = l.size() - (x - 1) * (d + 1);
	int nl = y, ng = x;
	loop(x) sum += g[i];
	loop(y) sum += l[i];
	ans = max(ans, sum);
	int z = (n - 1) / (d + 1) + 1;
	for (;ng < z;) {
		loop(d + 1) sum += l[nl++];
		sum += g[ng++];
		ans = max(ans, sum);
	}
	cout << ans << endl;
	return 0;
}
