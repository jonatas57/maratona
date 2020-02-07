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
	int n;
	cin >> n;
	string s;
	getchar();
	loop(n) {
		getline(cin, s);
		vector<ll> a;
		ll aux = 0;
		for (int i = 0;i <= s.length();i++) {
			if (isdigit(s[i])) aux *= 10, aux += s[i] - '0';
			else if (aux) a.push_back(aux), aux = 0;
		}
		int m = a.size();
		ll ans = 0;
		loop(m) {
			for (int j = i + 1;j < m;j++) {
				ans = max(ans, __gcd(a[i], a[j]));
			}
		}
		cout << ans << endl;
	}
	return 0;
}

