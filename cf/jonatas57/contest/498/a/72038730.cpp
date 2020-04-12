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

bool above(ll x, ll y, ll a, ll b, ll c) {
	return a * x + b * y + c > 0;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	ll x, y, w, z;
	cin >> x >> y >> w >> z;
	int n, ans = 0;
	cin >> n;
	int a, b, c;
	loop(n) {
		cin >> a >> b >> c;
		ans += above(x, y, a, b, c) ^ above(w, z, a, b, c);
	}
	cout << ans << endl;
	return 0;
}
