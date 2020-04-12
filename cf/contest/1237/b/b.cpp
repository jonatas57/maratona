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
	vi a(n), b(n);
	loop(n) cin >> a[i];
	loop(n) cin >> b[i];
	vb fined(n, false);
	int cnt = 0;
	for (int i = 0, j = 0;j < n;) {
		if (a[i] == b[j]) i++, j++;
		else if (fined[a[i]]) i++;
		else {
			fined[b[j]] = true;
			cnt++;
			j++;
		}
	}
	cout << cnt << endl;
	return 0;
}
