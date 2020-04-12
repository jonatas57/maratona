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

	int a, b, q;
	cin >> q;
	loop(q) {
		cin >> a >> b;
		string s;
		cin >> s;
		int ans = 0, cnt = 0;
		loop(s.length() + 1) {
			if (s[i] == '.') cnt++;
			else {
				cnt %= (a + b);
				if (cnt >= a) ans ^= 1;
				cnt = 0;
			}
		}
		cout << (ans ? "YES" : "NO") << endl;
	}
	return 0;
}
