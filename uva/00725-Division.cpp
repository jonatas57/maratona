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

int f(int a) {
	int ans = 0;
	loop(5) {
		ans |= 1 << (a % 10);
		a /= 10;
	}
	return ans;
}

bool check(int a) {return __builtin_popcount(f(a)) == 5;}

bool check(int a, int b) {return __builtin_popcount(f(a) | f(b)) == 10;}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	for (int i = 0;cin >> n and n;i++) {
		bool p = true;
		if (i) cout << endl;
		for (int i = 1234;i * n <= 98765;i++) {
			if (check(i) and check(i * n) and check(i, i * n)) {
				cout << i * n << " / " << setfill('0') << setw(5) << i << " = " << n << endl;
				p = false;
			}
		}
		if (p) cout << "There are no solutions for " << n << "." << endl;
	}
	return 0;
}

