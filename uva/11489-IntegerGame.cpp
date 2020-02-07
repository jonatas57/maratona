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

	int t;
	cin >> t;
	string n;
	while (t--) {
		cin >> n;
		int sum = 0;
		vi mod(3);
		each(c, n) {
			int x = c - '0';
			mod[x % 3]++;
			sum += x;
		}
		sum %= 3;
		int max = min(1, mod[sum]) + mod[0] - (mod[0] and sum % 3 == 0);
		cout << (max & 1 ? 'S' : 'T') << endl;
	}
	return 0;
}

