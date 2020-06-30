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
	string s;
	loop(t) {
		int n;
		cin >> n >> s;
		int lastzero = 0;
		string ans = "";
		loop(n) {
			if (s[i] == '0') lastzero = i;
		}
		int x = 0;
		for (;x < n and s[x] == '0';x++) ans += s[x];
		if (x < lastzero) {
			ans += '0';
			x = lastzero + 1;
		}
		for (;x < n;x++) ans += s[x];
		cout << ans << endl;
	}
	return 0;
}

