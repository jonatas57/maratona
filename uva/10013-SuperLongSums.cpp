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
	return {'0' + x % 10, x / 10};
}

string remZero(string s) {
	int x;
	for (x = 0;s[x] == '0';x++);
	return s.substr(s[x] == '\0' ? x - 1 : x);
}

string sum(string& s, string& t) {
	string a(s.length() + 1, '0');
	int carry = 0;
	for (int i = s.length() - 1;i >= 0;i--) {
		tie(a[i + 1], carry) = sum(s[i], t[i], carry);
	}
	if (carry) a[0] = '1';
	return remZero(a);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int n, m;
	cin >> n;
	loop(n) {
		if (i) cout << endl;
		string s = "", t = "";
		char a, b;
		cin >> m;
		loop(m) {
			cin >> a >> b;
			s += a;
			t += b;
		}
		cout << sum(s, t) << endl;
	}
	return 0;
}

