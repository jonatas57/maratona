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

int getLast(string& a) {
	int ans = 0;
	if (a.length()) {
		ans += a.back() - '0';
		a.pop_back();
	}
	return ans;
}

string sum(string a, string b) {
	string s = "";
	int carry = 0;
	while (!a.empty() or !b.empty()) {
		int z = getLast(a) + getLast(b) + carry;
		carry = 0;
		if (z > 9) z -= 10, carry = 1;
		s += '0' + z;
	}
	if (carry) s += '1';
	return string(riter(s));
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	string ans = "0", s;
	while (cin >> s and s != "0") {
		ans = sum(ans, s);
	}
	cout << ans << endl;
	return 0;
}

