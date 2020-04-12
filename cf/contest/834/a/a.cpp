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

	char a, b;
	int n;
	cin >> a >> b >> n;
	n %= 4;
	string s = "^>v<";
	int x;
	loop(4) if (a == s[i]) x = i;
	int ans = 0;
	if (b == s[(x + n) % 4]) ans |= 1;
	if (b == s[(x + 4 - n) % 4]) ans |= 2;
	cout << (ans == 1 ? "cw" : (ans == 2 ? "ccw" : "undefined")) << endl;
	return 0;
}

