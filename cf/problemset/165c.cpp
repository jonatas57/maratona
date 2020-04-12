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

	int k;
	string s;
	cin >> k >> s;
	int l = s.length();
	vector<ll> a(l + 1, 0);
	a[0] = 1;
	int cnt = 0;
	each(x, s) {
		if (x == '1') cnt++;
		a[cnt]++;
	}
	ll ans = 0;
	if (k) {
		for (int i = 0;i + k <= l;i++) {
			ans += a[i] * a[i + k];
		}
	}
	else {
		for (int i = 0;i <= l;i++) {
			ans += (a[i] * (a[i] - 1)) / 2;
		}
	}
	cout << ans << endl;
	return 0;
}

