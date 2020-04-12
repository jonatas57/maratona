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

	int n;
	cin >> n;
	int minn = 1;
	vi es;
	int j = 0;
	for (int i = 2;i * i <= n;i++) {
		if (n % i == 0) {
			minn *= i;
			es.push_back(0);
			while (n % i == 0) {
				es[j]++;
				n /= i;
			}
			j++;
		}
	}
	if (n > 1) {
		if (minn % n) minn *= n, es.push_back(1);
		else es[j]++;
	}
	int maxy = 0, ans = 0;
	each(x, es) {
		int y = ceil(log2(x));
		maxy = max(y, maxy);
	}
	each(x, es) if (pow(2, maxy) - x) {
		maxy++;
		break;
	}
	cout << minn << " " << maxy << endl;
	return 0;
}

