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
const double EPS = 1e-7;
const double PI = acos(-1);

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  loop(t) {
    string s;
    cin >> s;
    bool one = true;
    string t = "";
    bool last = false, ans= true;
    for (int i = 0;s[i] and ans;i++) {
      if ((s[i] == '1') xor one) {
        t += s[i];
        last = false;
      }
      else {
        if (last) {
          if (one) {
            one = false;
            t += s[i];
          }
          else ans = false;
          last = false;
        }
        else {
          last = true;
        }
      }
    }
    for (int i = 1;t[i] and ans;i++) if (t[i] < t[i - 1]) ans = false;
    cout << (ans ? "YES" : "NO") << endl;
  }
  return 0;
}

