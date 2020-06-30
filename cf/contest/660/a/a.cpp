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
	vi a(n), b;
	loop(n) cin >> a[i];
	b.push_back(a[0]);
	int ans = 0;
	loop(n - 1) {
		if (gcd(a[i], a[i + 1]) != 1) b.push_back(1), ans++;
		b.push_back(a[i + 1]);
	}
	cout << ans << endl;
	each(x, b) cout << x << " ";
	cout << endl;
	return 0;
}

