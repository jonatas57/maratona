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

	int t;
	cin >> t;
	vector<string> ss = {"Mile", "Juice"};
	loop(t) {
		int n;
		cin >> n;
		int x;
		int m = 0, j = 0;
		loop(n) {
			cin >> x;
			m += 10 * (x / 30 + 1);
			j += 15 * (x / 60 + 1);
		}
		cout << "Case " << i + 1 << ": ";
		if (m == j) cout << "Mile Juice " << m << endl;
		else cout << ss[m > j] << " " << min(m, j) << endl;
	}
	return 0;
}

