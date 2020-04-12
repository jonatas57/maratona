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

	string a, b;
	cin >> a >> b;
	int l = a.length();
	int ans = 0;
	loop(l) {
		int x = ans;
		if (a[i] == '0' and b[i] == '0') {
			if (i and (a[i - 1] == '0' or b[i - 1] == '0')) ans++;
			else if (l - i - 1) {
				if (a[i + 1] == '0') ans++, a[i + 1] = 'X';
				else if (b[i + 1] == '0') ans++, b[i + 1] = 'X';
			}
		}
		if (x != ans) a[i] = b[i] = 'X';
	}
	cout << ans << endl;
	return 0;
}

