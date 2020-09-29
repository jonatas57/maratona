#include <bits/stdc++.h>

using namespace std;

typedef long long          ll;
typedef unsigned long long ull;
typedef vector<int>         vi;
typedef vector<bool>       vb;
typedef map<int, int>      mii;
typedef pair<int, int>     ii;

#define INF                0x3f3f3f3f
#define INFLL              0x3f3f3f3f3f3f3f3f
#define each(x, s)         for(auto& x : s)
#define loop(x)            for(int i = 0;i < x;i++)
#define vloop(v, x)        for(int v = 0;v < x;v++)
#define avg(l, r)          l + (r - l) / 2
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

const ll mod = 1000000007;

void inc(string& s) {
  string t = string(riter(s));
  int carry = 1;
  for (int i = 0;carry;i++) {
    if (!t[i]) t += '1', carry = 0;
    else {
      t[i]++;
      if (t[i] > '9') {
        t[i] = '0';
      }
      else carry = 0;
    }
  }
  s = string(riter(t));
}

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  string rep = s.substr(0, k);
  string t = "", u = "";
  loop(n) t += rep[i % k];
  inc(rep);
  loop(n) u += rep[i % k];
  string ans = t >= s ? t : u;
  cout << ans.length() << endl << ans << endl;
  return 0;
}

