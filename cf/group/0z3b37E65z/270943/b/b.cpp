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

typedef tuple<int, int, int> tup;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	vector<ll> d1((n << 1) - 1, 0), d2((n << 1) - 1, 0);
	vector<vector<ll>> b(n, vector<ll>(n));
	loop(n) vloop(j, n) {
		cin >> b[i][j];
		d1[i + j] += b[i][j];
		d2[i - j + n - 1] += b[i][j];
	}
	vector<tup> ps;
	loop(n) vloop(j, n) {
		ll x = d1[i + j] + d2[i - j + n - 1] - b[i][j];
		ps.emplace_back(x, i, j);
	}
	sort(riter(ps));
	return 0;
}

