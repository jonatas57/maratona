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

auto sum(char a, char b, int carry) {
	int x = a - 'a' + b - 'a' + carry;
	carry = x / 26;
	x %= 26;
	return make_pair((char)x, carry);
}

string sum(string& a, string& b, int k) {
	string c(k, ' ');
	int carry = 0;
	for (int i = k - 1;i >= 0;i--) {
		tie(c[i], carry) = sum(a[i], b[i], carry);
	}
	c[0] += carry * 26;
	return c;
}

string div(string s, int d, int k) {
	string ans(k, '.');
	int dd = 0;
	loop(k) {
		dd *= 26;
		dd += s[i];
		ans[i] = 'a' + dd / d;
		dd %= d;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int k;
	cin >> k;
	string s, t;
	cin >> s >> t;
	cout << div(sum(s, t, k), 2, k) << endl;
	return 0;
}

