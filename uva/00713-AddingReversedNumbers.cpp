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

pair<char, int> sum(char a, char b, int carry) {
	int x = a - '0' + b - '0' + carry;
	return make_pair('0' + x % 10, x / 10);
}

string remZero(string s) {
	int x = 0;
	for (;s[x] == '0';x++);
	string t = s.substr(x);
	return t.empty() ? "0" : t;
}

string sum(string s, string t) {
	if (s.length() > t.length()) swap(s, t);
	int l = s.length();
	int carry = 0;
	char c;
	string ans = "";
	for (int i = 0;t[i];i++) {
		tie(c, carry) = sum(t[i], i >= l ? '0' : s[i], carry);
		ans += c;
	}
	if (carry) ans += '1';
	return remZero(ans);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n;
	cin >> n;
	loop(n) {
		string a, b;
		cin >> a >> b;
		cout << sum(a, b) << endl;
	}
	return 0;
}

