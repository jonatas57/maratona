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

set<int> divs(int n) {
	set<int> ds;
	for (int i = 1;i * i <= n;i++) {
		if (n % i == 0) {
			ds.insert(i);
			ds.insert(n / i);
		}
	}
	ds.erase(n);
	return ds;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cout << "PERFECTION OUTPUT" << endl;
	while (cin >> n and n) {
		set<int> ds = divs(n);
		int sum = 0;
		each(x, ds) sum += x;
		cout << setw(5) << n << "  " << (sum > n ? "ABUNDANT" : (sum < n ? "DEFICIENT" : "PERFECT")) << endl;
	}
	cout << "END OF OUTPUT" << endl;
	return 0;
}

