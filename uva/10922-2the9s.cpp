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
	while (cin >> s and s != "0") {
		int deg = 0;
		int sum = 0;
		each(c, s) sum += c - '0';
		while (sum % 9 == 0) {
			deg++;
			int x = sum, last = sum;
			sum = 0;
			while (x) {
				sum += x % 10;
				x /= 10;
			}
			if (sum == last) break;
		}
		if (deg) cout << s << " is a multiple of 9 and has 9-degree " << deg << "." << endl;
		else cout << s << " is not a multiple of 9." << endl;
	}
	return 0;
}

