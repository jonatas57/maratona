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
#define keach(k, v, s)     for(auto& [k, v] : s)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define cc(x)              cerr << #x << " = " << x << endl;

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	string s, t;
	cin >> s >> t;
	int j = 0;
	for (int i = 0;s[i] != '\0';i++) {
		if (s[i] == t[j]) j++;
	}
	cout << (t[j] == '\0' ? "YES" : "NO") << endl;
	return 0;
}

