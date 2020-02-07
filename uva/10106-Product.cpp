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

void remZero(string& a) {
	int x = 0;
	while (a[x] and a[x] == '0') x++;
	a = a.substr(x);
	if (a.empty()) a = "0";
}

pair<char, int> sum(char a, char b, int carry) {
	int x = a + b - '0' - '0' + carry;
	return make_pair((x % 10) + '0', x / 10);
}

string sum(string a, string b) {
	int la = a.length(), lb = b.length();
	if (la < lb) swap(la, lb), swap(a, b);
	a = "0" + a;
	b = string(la + 1 - lb, '0') + b;
	string c(la + 1, '0');
	int carry = 0;
	for (int i = la;i >= 0;i--) {
		tie(c[i], carry) = sum(a[i], b[i], carry);
	}
	remZero(c);
	return c;
}

string operator*(string a, string b) {
	remZero(a);
	remZero(b);
	int la = a.length(), lb = b.length();
	if (la + lb < 18) return to_string(stoll(a, nullptr, 10) * stoll(b, nullptr, 10));
	if (la < lb) swap(la, lb), swap(a, b);
	int x = la / 2;
	string z(x, '0');
	string a0 = a.substr(0, la - x), a1 = a.substr(la - x);
	string b0 = (lb - x > 0 ? b.substr(0, lb - x) : "0"), b1 = b.substr(max(0, lb - x));
	return sum(a0 * b0 + z + z, sum(sum(a0 * b1, a1 * b0) + z, a1 * b1));
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	string x, y;
	while (cin >> x >> y) {
		cout << x * y << endl;
	}
	return 0;
}

