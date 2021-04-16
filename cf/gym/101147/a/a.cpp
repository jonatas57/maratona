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

  freopen("powers.in", "r", stdin);

  int t;
  cin >> t;
  loop(t) {
    int g;
    cin >> g;
    int ans = 0;
    loop(g) {
      int b, n;
      cin >> b >> n;
      int mex;
      if (b & 1) mex = n & 1;
      else {
        int x = n % (b + 1);
        if (x == b) mex = 2;
        else mex = x & 1;
      }
      ans ^= mex;
    }
    cout << (ans ? 1 : 2) << endl;
  }
  return 0;
}

