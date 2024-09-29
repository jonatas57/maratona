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
  vi bs = {0, 1, 0, -1, -1, 0, 1, 0};
  loop(t) {
    ll b, c, d;
    cin >> b >> c >> d;
    ll a = 0;
    for (ll i = 0, m = 1;i < 64;i++, m <<= 1) {
      int bb = !!(b & m), bc = !!(c & m), bd = !!(d & m);
      int x = bb * 4 + bc * 2 + bd;
      if (bs[x] == -1) {
        a = -1;
        break;
      }
      else a += m * bs[x];
    }
    cout << a << endl;
  }
  return 0;
}

