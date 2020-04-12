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

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int a, b;
	cin >> a >> b;
	vi ans;
	if (a != 1) {
		ans.resize(a, 1);
	}
	if (b != 1) {
		vi aux(b, -1);
		ans[0] += b;
		aux[0] = -a;
		ans.insert(ans.end(), iter(aux));
	}
	if (!ans.size()) ans.push_back(1);
	int x = 0;
	each(y, ans) {
		x += y;
		cout << x << " ";
	}
	cout << endl;
	return 0;
}

