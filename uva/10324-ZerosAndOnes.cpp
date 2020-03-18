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

	string s;
	for (int i = 1;cin >> s;i++) {
		int n, a, b;
		vi acc(s.length() + 1, 0);
		for (int i = 0;s[i];i++) {
			acc[i + 1] = acc[i] + (s[i] - '0');
		}
		cin >> n;
		cout << "Case " << i << ":" << endl;
		loop(n) {
			cin >> a >> b;
			if (a > b) swap(a, b);
			int x = acc[a], y = acc[b + 1];
			cout << (x == y or b - a + 1 == y - x ? "Yes" : "No") << endl;
		}
	}
	return 0;
}

