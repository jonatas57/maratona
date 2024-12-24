#include <bits/stdc++.h>

using namespace std;

typedef long long      ll;
typedef vector<int>    vi;
typedef vector<bool>   vb;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const ll  INFLL = 0x3f3f3f3f3f3f3f3fll;

#define each(x, s)  for (auto& x : s)
#define loop(x)     for (int i = 0;i < x;i++)
#define vloop(v, x) for (int v = 0;v < x;v++)
#define iter(a)     a.begin(), a.end()
#define riter(a)    a.rbegin(), a.rend()
#define endl        "\n"

int main() {
  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
  
  int t;
  cin >> t;
  loop(t) {
    ll l, r, g;
    cin >> l >> r >> g;
    ll x = ((l - 1) / g + 1) * g, y = r / g * g;
    ll A = -1, B = -1;
    for (ll i = x;i <= y and (A == -1 or B == -1 or B - A < y - i);i += g) {
      for (ll j = y;j >= x and (A == -1 or B == -1 or B - A < j - i);j -= g) {
        if (gcd(i, j) == g) {
          A = i;
          B = j;
        }
      }
    }
    cout << A << " " << B << endl;
  }
  return 0;
}

