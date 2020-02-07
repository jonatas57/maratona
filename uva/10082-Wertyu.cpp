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

	string a = " BCDEFGHIJKLMNOPRSTUVWXY,./[];\\1234567890-=\'";
	string b = " VXSWDFGUHJKNBIOEARYCQZTM,.P[L]`1234567890-;";
	map<char, char> f;
	loop((int)a.size()) f[a[i]] = b[i];
	string s;
	while (getline(cin, s)) {
		each(c, s) c = f[c];
		cout << s << endl;
	}
	return 0;
}

