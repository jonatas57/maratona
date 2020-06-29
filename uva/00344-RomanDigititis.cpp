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

//0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 2 3 3 3 3 3 3 3 3 3 3 1 1 1 1 1 1 1 1 1 1 
	
	int n;
	vi si = {0, 0, 1, 3, 6, 7}, si2 = {0, 0, 1, 2, 3, 1};
	while (cin >> n and n) {
		int i = n / 5 * 7 + si[n % 5 + 1];
		int v = (n + 2) / 10 * 5 + max(0, (n + 2) % 10 - 5);
		int aux = n % 50, x = n / 50 * 70 + 10 * si[aux / 10] + (aux % 10 + 1) * si2[aux / 10 + 1] + (n + 1) / 10;
		int l = min(89, n) - min(39, n);
		int c = max(0, n - 89);
		cout << n << ": " << i << " i, " << v << " v, " << x << " x, " << l << " l, " << c << " c" << endl;
	}
	return 0;
}

