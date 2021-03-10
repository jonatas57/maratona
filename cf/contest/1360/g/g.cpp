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
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if (n * a == m * b) {
      cout << "YES" << endl;
      int g1 = gcd(n, b), g2 = gcd(m, a);
      n /= g1, m /= g2, a /= g2, b /= g1;
      vector<string> ans(n, string(m, '0'));
      vi cntc(m, 0);
      loop(n) {
        int cntl = 0;
        vloop(j, m) {
          if (cntl < a and cntc[(i + j) % m] < b) cntl++, cntc[(i + j) % m]++, ans[i][(i + j) % m] = '1';
        }
      }
      loop(g1) {
        vloop(j, n) {
          vloop(k, g2) cout << ans[j];
          cout << endl;
        }
      }
    }
    else cout << "NO" << endl;
  }
  return 0;
}

