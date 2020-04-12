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

	int n, k;
	string s;
	cin >> n >> k >> s;
	string spell(1, s[0]);
	vi a;
	for (int i = 0;s[i];i++) if (s[i] == s[0]) a.push_back(i);
	int cnt = a.size();
	for (int i = 1;cnt >= k and s[i];i++) {
		int aux = 0;
		each(x, a) {
			if (x == -1) continue;
			if (s[x + 1] == s[i]) x++;
			else x = -1, aux++;
		}
		if (cnt - aux < k) break;
		else spell += s[i], cnt -= aux;
	}
	cout << (cnt < k ? "NO IDEA" : spell) << endl;
	return 0;
}

