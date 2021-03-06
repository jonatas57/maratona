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
	cin >> n;
	string s;
	loop(n) {
		cin >> s;
		bool par = false;
		int sum = 0, z = 0;
		each(c, s) {
			int x = c - '0';
			if (!x) {
				z++;
				if (z > 1) par = true;
			}
			else if (x % 2 == 0) par = true;
			sum += x;
		}
		cout << (sum == 0 or (z and par and sum % 3 == 0) ? "red" : "cyan") << endl;
	}
	return 0;
}

