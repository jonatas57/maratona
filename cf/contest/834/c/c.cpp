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

ll bb(ll l, ll r, ll x) {
	ll mid = avg(l, r);
	ll y = mid * mid * mid;
	if (x == y) return mid;
	else if (l == r) return -1;
	else if (x < y) return bb(l, mid, x);
	else return bb(mid + 1, r, x);
}

bool check(ll x, ll y) {
	ll r = bb(1, 1000001, x * y);
	return r != -1 and r * r * r == x * y and x % r == 0 and y % r == 0;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	ll n, a, b;
	cin >> n;
	loop(n) {
		cin >> a >> b;
		cout << (check(a, b) ? "Yes" : "No") << endl;
	}
	return 0;
}
