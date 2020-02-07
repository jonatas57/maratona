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

	ll a, b;
	while (cin >> a >> b and a | b) {
		int cnt = 0, carry = 0;
		while (a | b) {
			int x = a % 10 + b % 10 + carry;
			if (x >= 10) carry = 1, cnt++;
			else carry = 0;
			a /= 10;
			b /= 10;
		}
		cout << (cnt ? to_string(cnt) : "No") << " carry operation" << (cnt > 1 ? "s" : "") << "." << endl;
	}
	return 0;
}

