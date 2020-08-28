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

vi parse(string& s, int& pos, int n) {
  int x = 0;
  bool neg = false;
  char op = ' ';
  vi seq;
  for (;s[pos];pos++) {
    if (isdigit(s[pos])) {
      x *= 10;
      x += s[pos] - '0';
    }
    else if (s[pos] == '-') {
      neg = true;
    }
    else if (s[pos] == '[') {
      if (neg) x = -x;
      pos++;
      seq = parse(s, pos, n);
      if (op == '*') {
        loop(n) {
          seq[i] = i ? seq[i - 1] * seq[i] : seq[i] * x;
        }
      }
      else {
        int aux;
        loop(n) {
          int tmp = seq[i];
          seq[i] = i ? seq[i - 1] + aux : x;
          aux = tmp;
        }
      }
    }
    else if (s[pos] == ']') {
      if (neg) x = -x;
      if (op == ' ') {
        return vi(n, x);
      }
      return seq;
    }
    else op = s[pos];
  }
  return seq;
}

int main() {
	ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  
  string s;
  int n;
  while (cin >> s >> n) {
    int pos = 1;
    vi ans = parse(s, pos, n);
    loop(n) {
      if (i) cout << " ";
      cout << ans[i];
    }
    cout << endl;
  }
	return 0;
}
