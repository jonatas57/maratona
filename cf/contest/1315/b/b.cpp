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
		int a, b, p;
		cin >> a >> b >> p;
		string s;
		cin >> s;
		int l = s.length(), ans = 0, val = 0;
		s.pop_back();
		for (int i = l - 2;i >= 0 and ans == 0;i--) {
			if (s[i] != s[i + 1]) val += (s[i] == 'A' ? a : b);
			if (val > p) ans = i + 1;
		}
		cout << ans + 1 << endl;
	}
	return 0;
}

