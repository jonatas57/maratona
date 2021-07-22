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
#define avg(l, r)          (l + r) >> 1
#define iter(a)            a.begin(), a.end()
#define riter(a)           a.rbegin(), a.rend()
#define endl               "\n"

const ll mod = 1000000007;
const double EPS = 1e-7;
const double PI = acos(-1);

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int q;
  cin >> q;
  loop(q) {
    string s, t;
    cin >> s >> t;
    bool ans = false;
    for (int i = s.length() - 1, j = t.length() - 1;i >= 0;) {
      if (s[i] == t[j]) i--, j--;
      else i -= 2;
      if (j < 0) ans = true;
    }
    cout << (ans ? "YES" : "NO") << endl;
  }
  return 0;
}

