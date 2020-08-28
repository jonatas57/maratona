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
  int x = a + b + carry - '0' - '0';
  return make_pair('0' + (x % 10), x / 10);
}

string sum(string a, string b) {
  string c = "";
  int carry = 0;
  int la = a.length(), lb = b.length();
  if (la < 18 and lb < 18) {
    return to_string(stoll(a) + stoll(b));
  }
  loop(max(la, lb)) {
    char x;
    tie(x, carry) = sum(la - 1 >= i ? a[la - i - 1] : '0', lb - 1 >= i ? b[lb - i - 1] : '0', carry);
    c += x;
  }
  if (carry) c += '1';
  return string(riter(c));
}

string mult(string a, ll x) {
  int l = a.length();
  if (l <= 18) return to_string(stoll(a) * x);
  string c = "";
  int carry = 0;
  loop(l) {
    int aux = (a[l - 1 - i] - '0') * x + carry;
    carry = aux / 10;
    c += '0' + aux % 10;
  }
  if (carry) c += '0' + carry;
  return string(riter(c));
}

string square(string& n) {
  int l = n.length();
  if (l < 9) {
    ll x = stoll(n);
    return to_string(x * x);
  }
  string ans = "0";
  loop(l) {
    string aux = mult(n, n[l - i - 1] - '0') + string(i, '0');
    ans = sum(ans, aux);
  }
  return ans;
}

void decr(string& n) {
  int x = n.length();
  for (int l = x - 1;l >= 0;) {
    if (n[l] == '0') {
      n[l] = '9';
      l--;
    }
    else {
      n[l]--;
      break;
    }
  }
  if (x > 1 and n[0] == '0') n = n.substr(1);
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  string n;
  while (cin >> n) {
    if (n == "0") {
      cout << 1 << endl;
      continue;
    }
    decr(n);
    cout << sum(square(n), sum(n, "2")) << endl;
  }
	return 0;
}

