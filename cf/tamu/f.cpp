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
	cin.tie(NULL);cout.tie(NULL);

	int n, m;
	string text, msg;
	cin >> n >> m;
	getchar();
	getline(cin, text);
	cin >> msg;
	map<char, int> mcnt, tcnt;
	each(c, msg) mcnt[c]++;
	each(c, text) tcnt[c]++;
	int ans = INF;
	for (auto& [c, q] : mcnt) {
		int x = tcnt[c] / q;
		ans = min(ans, x);
	}
	cout << ans << endl;
	return 0;
}

