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
    int n, m, k;
    cin >> n >> m >> k;
    vb big(n, false);
    char c;
    loop(n) {
      cin >> c;
      if (c == 'B') big[i] = true;
    }
    int ans = 0, x;
    loop(m) {
      cin >> c;
      if (c == 'W') {
        cin >> x;
        x--;
        if (x < k and !big[x]) ans++;
        if (x >= k) {
          k = x + 1;
        }
      }
      else {
        k = n;
      }
    }
    cout << ans << endl;
  }
  return 0;
}

