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
	while (cin >> n and n) {
		vi hor(n, 0), ver(n, 0);
		int x;
		loop(n) {
			vloop(j, n) {
				cin >> x;
				hor[i] += x;
				ver[j] += x;
			}
		}
		int a, b, cnth = 0, cntv = 0;
		loop(n) {
			if (hor[i] & 1) cnth++, a = i + 1;
			if (ver[i] & 1) cntv++, b = i + 1;
		}
		if (!cnth and !cntv) cout << "OK" << endl;
		else if (cnth == 1 and cntv == 1) cout << "Change bit (" << a << "," << b << ")" << endl;
		else cout << "Corrupt" << endl;
	}
	return 0;
}

