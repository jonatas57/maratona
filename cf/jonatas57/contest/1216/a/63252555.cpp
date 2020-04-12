#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>	       vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define MAX                100000
#define N                  4 * MAX + 10
#define MOD                1000000007
#define each(x, s)         for(auto& x : s)
#define ceach(x, s)        for(auto const& x : s)
#define rep(x, y, z)       for(int i = x;i < y;i+=z)
#define loop(x)	           for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2

int check(char& a, char& b) {
	int ans = 0;
	if (a == 'a') {
		if (b != 'b') b = 'b', ans++;
	}
	else if (b == 'b') {
		if (a != 'a') a = 'a', ans++;
	}
	else if (a == 'b') {
		if (b != 'a') b = 'a', ans++;
	}
	else if (b == 'a') {
		if (a != 'b') a = 'b', ans++;
	}
	else {
		a = 'a';
		b = 'b';
		ans += 2;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, ans = 0;
	string s;
	cin >> n >> s;
	for (int i = 0;i < n;i += 2) {
		ans += check(s[i], s[i + 1]);
	}
	cout << ans << endl;
	cout << s << endl;
	return 0;
}

